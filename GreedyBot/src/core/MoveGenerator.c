#include <stdint.h>
#include <stdio.h>
#include "BitBoard.h"
#include "MoveGenerator.h"
#include "Magics.h"

/*

    the general movegen strat will be to obtain a mask for the given piece,
    check if that piece is pinned to the king, obtain a movement mask for the peice, 
    depening on if it is pinned to the king and which squares are taken by friendly pieces we determine the possible moves

*/


static inline uint64_t pinMask(uint8_t square1, uint8_t square2){




}


void makeMove(BitBoard *board, Move move){

    RawBoard *friendlyPieces, *enemyPieces;

    // break the move down into its parts
    uint64_t startSquare = 1ull << (move & startMask);
    uint64_t endSquare = 1ull << ((move & endMask) >> 6);
    uint32_t isCapture = move & isCaptureMask;
    uint32_t misc = (move & miscMask) >> 12;
    uint32_t piece = (move & pieceMask) >> 16;

    // these three lines depend on the BitBoard structure as it is on sept 26th 2024 at 5:17PM
    // please forgive me for these sins
    uint64_t *movedPiece = ((uint64_t*)board + piece);
    friendlyPieces = ((RawBoard*)board + board->whiteToMove);
    enemyPieces = ((RawBoard*)board + !board->whiteToMove);

    uint64_t *friendlyBoard = (&(board->blackPieces) + board->whiteToMove);

    // the move mask has a 1 on the start and end square and 0s everywhere else, 
    // so XORing it with the bitboard of the moved piece toggels off the start bit where the piece started 
    // and toggles on the end square where the piece ends
    *movedPiece ^= startSquare | endSquare;
    *friendlyBoard ^= startSquare | endSquare;

    // now if the move was a castling move we have to also move the appropriate rook
    // use the predefined masks for this since there are only 4 castling moves
    if(misc == (uint16_t)2){ // kingside castle
        friendlyPieces->r ^= board->whiteToMove ? whiteKingsideCastle : blackKingsideCastle;
        *friendlyBoard ^= board->whiteToMove ? whiteKingsideCastle : blackKingsideCastle;
    }
    else if(misc == (uint16_t)3){ // queenside castle
        friendlyPieces->r ^= board->whiteToMove ? whiteQueensideCastle : blackQueensideCastle;
        *friendlyBoard ^= board->whiteToMove ? whiteQueensideCastle : blackQueensideCastle;
    }

    if(isCapture){ // if the move is a capture we have to remove the enemy piece from the square
        
        uint64_t notEndSquare;

        if(misc == (uint16_t)5){ // this is an enpassant capture
            notEndSquare = board->whiteToMove ? ~(endSquare >> 8) : ~(endSquare << 8);
        }
        else{
            notEndSquare = ~endSquare;
        }

        // we can simply turn off this bit for every enemy piece because there cant be a piece there 
        // and this avoids control flow which would end up being more work overall
        enemyPieces->k &= notEndSquare;
        enemyPieces->q &= notEndSquare;
        enemyPieces->r &= notEndSquare;
        enemyPieces->b &= notEndSquare;
        enemyPieces->n &= notEndSquare;
        enemyPieces->p &= notEndSquare;
        *(&board->blackPieces + !board->whiteToMove) &= notEndSquare;

    }

    if(move & isPromoMask){ // if the move is a promo we have to add a new piece and remove the pawn from the end of the board
        
        *movedPiece &= ~endSquare; // first remove the pawn
        *((uint64_t*)friendlyPieces + 1 + ((move & promoPieceMask) >> 12)) |= endSquare; // now add the promoted piece (another sin)

    }

    // update the other data starting with move counter
    board->moves += (uint16_t)!board->whiteToMove; // if it was black that just moved we update the move counter

    // update the halfmove clock according to if the move was a pawn move capture or neither
    if(*movedPiece == friendlyPieces->p || isCapture){
        board->halfMoves = 0;
    }
    else{
        board->halfMoves++;
    }

    // update the en passant square if it was a double pawn push
    if(misc == (uint16_t)1){
        board->enPassant = board->whiteToMove ? endSquare >> 8 : endSquare << 8;
    }
    else{
        board->enPassant = 0ull;
    }

    // update castling rights and kingpos if king moved
    if(*movedPiece == friendlyPieces->k){
        board->castling &= ~(board->whiteToMove ? (uint8_t)12 : (uint8_t)3);
        *(&board->blackKingPos + board->whiteToMove) = __builtin_ctzll(friendlyPieces->k);
    }
    if(!(board->white.r & H1)) board->castling &= ~((uint8_t)8);
    if(!(board->white.r & A1)) board->castling &= ~((uint8_t)4);
    if(!(board->black.r & H8)) board->castling &= ~((uint8_t)2);
    if(!(board->black.r & A8)) board->castling &= ~((uint8_t)1);

    
    // finally we switch the player to move
    board->whiteToMove = !board->whiteToMove;


    return;

}

int generateMovesWhite(BitBoard *board, Move *moves){

    uint64_t opBoard = board->blackPieces;
    uint64_t myBoard = board->whitePieces;
    // a board that contains all pieces
    uint64_t wholeBoard = opBoard | myBoard;

    int pos = 0; // where in the movelist to put moves


    uint64_t pieces = myBoard;
    int square = 63 - __builtin_clzll(pieces);
    uint64_t currentSquare = 1ull << square;
    while(pieces){

        if(currentSquare & board->white.p){ // found a pawn

            if(!((currentSquare << 8) & wholeBoard)){ // there is nothing stopping a single pawn push
                if(square < H7num){ // no promotion
                    
                    *(moves + pos) = buildMove(square, (square + 8), 0, 6);
                    pos++;

                    if(square < H3num && !((currentSquare << 16) & wholeBoard)){ // generate the double pawn push
                        *(moves + pos++) = buildMove(square, (square + 16), 1, 6);
                    }

                }
                else{ // promos

                    *(moves + pos++) = buildMove(square, (square + 8), 8, 6);

                    *(moves + pos++) = buildMove(square, (square + 8), 9, 6);

                    *(moves + pos++) = buildMove(square, (square + 8), 10, 6);

                    *(moves + pos++) = buildMove(square, (square + 8), 11, 6);
                }

                
            }

            // check if we can capture with the pawn
            uint64_t pawnCaptures = basicPawnMasksWhite[square] & opBoard;
            int capturePos = 63 - __builtin_clzll(pawnCaptures);
            while(pawnCaptures){
                if(capturePos < 56){
                    *(moves + pos++) = buildMove(square, capturePos, 4, 6);
                }
                else{ // promo captures
                    *(moves + pos++) = buildMove(square, capturePos, 12, 6);

                    *(moves + pos++) = buildMove(square, capturePos, 13, 6);

                    *(moves + pos++) = buildMove(square, capturePos, 14, 6);

                    *(moves + pos++) = buildMove(square, capturePos, 15, 6);
                }

                pawnCaptures ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(pawnCaptures);
            }

            // finally check enpassant captures
            uint64_t enPassant = basicPawnMasksWhite[square] & board->enPassant;
            if(enPassant){
                *(moves + pos++) = buildMove(square, __builtin_ctzll(enPassant), 5, 6);
            }

        }
        else if(currentSquare & board->white.n){ // found a knight

            uint64_t knightMoves = basicKnightMasks[square] & ~myBoard;
            int capturePos = 63 - __builtin_clzll(knightMoves);
            while(knightMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 7);

                knightMoves ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(knightMoves);
            }

        }
        else if(currentSquare & board->white.b){ // found a bishop

            uint64_t bishopMoves = getBishopAttacks(square, wholeBoard) & ~myBoard;
            int capturePos = 63 - __builtin_clzll(bishopMoves);
            while(bishopMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 8);

                bishopMoves ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(bishopMoves);
            }

        }
        else if(currentSquare & board->white.r){ // found a rook

            uint64_t rookMoves = getRookAttacks(square, wholeBoard) & ~myBoard;
            int capturePos = 63 - __builtin_clzll(rookMoves);
            while(rookMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 9);

                rookMoves ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(rookMoves);
            }

        }
        else if(currentSquare & board->white.q){ // found a queen

            uint64_t queenMoves = (getBishopAttacks(square, wholeBoard) | getRookAttacks(square, wholeBoard)) & ~myBoard;
            int capturePos = 63 - __builtin_clzll(queenMoves);
            while(queenMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 10);

                queenMoves ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(queenMoves);
            }

        }
        else if(currentSquare & board->white.k){ // found a king

            uint64_t kingMoves = basicKingMasks[square] & ~myBoard;
            int capturePos = 63 - __builtin_clzll(kingMoves);
            while(kingMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 11);

                kingMoves ^= (1ull << capturePos);
                capturePos = 63 - __builtin_clzll(kingMoves);
            }

            // also have to check for castling moves
            if(!(6ull & wholeBoard) && (board->castling & (uint16_t)8)){ // white has the right to castle kingside

                BitBoard temp = *board;
                temp.whiteToMove = 0;

                if(!isSquareAttacked(&temp, E1num) && !isSquareAttacked(&temp, F1num) && !isSquareAttacked(&temp, G1num)){
                    *(moves + pos++) = buildMove(square, G1num, 2, 11);
                }

            }

            if(!(112ull & wholeBoard) && (board->castling & (uint16_t)4)){ // white has the right to castle queenside
                BitBoard temp = *board;
                temp.whiteToMove = 0;

                if(!isSquareAttacked(&temp, E1num) && !isSquareAttacked(&temp, D1num) && !isSquareAttacked(&temp, C1num)){
                    *(moves + pos++) = buildMove(square, C1num, 3, 11);
                }
            }

        }

        pieces ^= currentSquare;
        square = 63 - __builtin_clzll(pieces);
        currentSquare = 1ull << square;

    }

    return pos;


}

int generateMovesBlack(BitBoard *board, Move *moves){

    uint64_t opBoard = board->whitePieces;
    uint64_t myBoard = board->blackPieces;
    // a board that contains all pieces
    uint64_t wholeBoard = opBoard | myBoard;

    int pos = 0; // where in the movelist to put moves


    uint64_t pieces = myBoard;
    int square = __builtin_ctzll(pieces);
    uint64_t currentSquare = 1ull << square;
    while(pieces){

        if(currentSquare & board->black.p){ // found a pawn

            if(!((currentSquare >> 8) & wholeBoard)){ // there is nothing stopping a single pawn push
                if(square > A2num){ // no promotion
                    
                    *(moves + pos++) = buildMove(square, (square - 8), 0, 0);

                    if(square > A6num && !((currentSquare >> 16) & wholeBoard)){ // generate the double pawn push
                        *(moves + pos++) = buildMove(square, (square - 16), 1, 0);
                    }

                }
                else{ // promos

                    *(moves + pos++) = buildMove(square, (square - 8), 8, 0);

                    *(moves + pos++) = buildMove(square, (square - 8), 9, 0);

                    *(moves + pos++) = buildMove(square, (square - 8), 10, 0);

                    *(moves + pos++) = buildMove(square, (square - 8), 11, 0);
                }

                
            }

            // check if we can capture with the pawn
            uint64_t pawnCaptures = basicPawnMasksBlack[square] & opBoard;
            int capturePos = __builtin_ctzll(pawnCaptures);
            while(pawnCaptures){
                if(capturePos > 7){
                    *(moves + pos++) = buildMove(square, capturePos, 4, 0);
                }
                else{ // promo captures
                    *(moves + pos++) = buildMove(square, capturePos, 12, 0);

                    *(moves + pos++) = buildMove(square, capturePos, 13, 0);

                    *(moves + pos++) = buildMove(square, capturePos, 14, 0);

                    *(moves + pos++) = buildMove(square, capturePos, 15, 0);
                }

                pawnCaptures ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(pawnCaptures);
            }

            // finally check enpassant captures
            uint64_t enPassant = basicPawnMasksBlack[square] & board->enPassant;
            if(enPassant){
                *(moves + pos++) = buildMove(square, __builtin_ctzll(enPassant), 5, 0);
            }

        }
        else if(currentSquare & board->black.n){ // found a knight

            uint64_t knightMoves = basicKnightMasks[square] & ~myBoard;
            int capturePos = __builtin_ctzll(knightMoves);
            while(knightMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 1);

                knightMoves ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(knightMoves);
            }

        }
        else if(currentSquare & board->black.b){ // found a bishop

            uint64_t bishopMoves = getBishopAttacks(square, wholeBoard) & ~myBoard;
            int capturePos = __builtin_ctzll(bishopMoves);
            while(bishopMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 2);

                bishopMoves ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(bishopMoves);
            }

        }
        else if(currentSquare & board->black.r){ // found a rook

            uint64_t rookMoves = getRookAttacks(square, wholeBoard) & ~myBoard;
            int capturePos = __builtin_ctzll(rookMoves);
            while(rookMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 3);

                rookMoves ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(rookMoves);
            }

        }
        else if(currentSquare & board->black.q){ // found a queen

            uint64_t queenMoves = (getBishopAttacks(square, wholeBoard) | getRookAttacks(square, wholeBoard)) & ~myBoard;
            int capturePos = __builtin_ctzll(queenMoves);
            while(queenMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 4);

                queenMoves ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(queenMoves);
            }

        }
        else if(currentSquare & board->black.k){ // found a king

            uint64_t kingMoves = basicKingMasks[square] & ~myBoard;
            int capturePos = __builtin_ctzll(kingMoves);
            while(kingMoves){
                int code = ((1ull << capturePos) & opBoard) ? 4 : 0;
                *(moves + pos++) = buildMove(square, capturePos, code, 5);

                kingMoves ^= (1ull << capturePos);
                capturePos = __builtin_ctzll(kingMoves);
            }

            // also have to check for castling moves
            if(!(432345564227567616ull & wholeBoard) && (board->castling & (uint16_t)2)){ // black has the right to castle kingside

                BitBoard temp = *board;
                temp.whiteToMove = 1;

                if(!isSquareAttacked(&temp, E8num) && !isSquareAttacked(&temp, F8num) && !isSquareAttacked(&temp, G8num)){
                    *(moves + pos++) = buildMove(square, G8num, 2, 5);
                }

            }

            if(!(8070450532247928832ull & wholeBoard) && (board->castling & (uint16_t)1)){ // black has the right to castle queenside
                BitBoard temp = *board;
                temp.whiteToMove = 1;

                if(!isSquareAttacked(&temp, E8num) && !isSquareAttacked(&temp, D8num) && !isSquareAttacked(&temp, C8num)){
                    *(moves + pos++) = buildMove(square, C8num, 3, 5);
                }
            }

        }

        pieces ^= currentSquare;
        square = __builtin_ctzll(pieces);
        currentSquare = 1ull << square;

    }

    return pos;

    
}
