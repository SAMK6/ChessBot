#include <stdint.h>
#include <stdio.h>
#include "BitBoard.h"
#include "MoveGenerator.h"
#include "BitMasks.h"


/*

    the general movegen strat will be to obtain a mask for the given piece,
    check if that piece is pinned to the king, obtain a movement mask for the peice, 
    depening on if it is pinned to the king and which squares are taken by friendly pieces we determine the possible moves

*/

BitBoard makeMove(BitBoard board, Move move, char piece){

    RawBoard *friendlyPieces, *enemyPieces;
    uint64_t *movedPiece;

    // break the move down into its parts
    uint64_t startSquare = 1ull << (move & startMask);
    uint64_t endSquare = 1ull << ((move & endMask) >> 6);
    uint16_t isCapture = move & isCaptureMask;
    uint16_t isPromo = move & isPromoMask;
    uint16_t misc = (move & miscMask) >> 14;

    // choce the appropriate pieces for the move
    switch(piece){
        case 'K':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->k;
            break;
        case 'Q':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->q;
            break;
        case 'R':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->r;
            break;
        case 'B':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->b;
            break;
        case 'N':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->n;
            break;
        case 'P':
            friendlyPieces = &board.white;
            enemyPieces = &board.black;
            movedPiece = &friendlyPieces->p;
            break;
        case 'k':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->k;
            break;
        case 'q':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->q;
            break;
        case 'r':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->r;
            break;
        case 'b':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->b;
            break;
        case 'n':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->n;
            break;
        case 'p':
            friendlyPieces = &board.black;
            enemyPieces = &board.white;
            movedPiece = &friendlyPieces->p;
            break;
        default:
            break;
    }

    *movedPiece &= ~startSquare; // toggle the start squre bit to 0
    *movedPiece |= endSquare; // toggle the end bit square to 1

    if(isCapture){ // if the move is a capture we have to remove the enemy piece from the square
        
        uint64_t notEndSquare;

        if(!isPromo && misc == (uint16_t)1){ // this is an enpassant capture
            if(friendlyPieces == &board.black){ // we are playing as black
                notEndSquare = ~(endSquare << 8);
            }
            else{ // we are playing as white
                notEndSquare = ~(endSquare >> 8);
            }
        }
        else{
            notEndSquare = ~endSquare;
        }

        enemyPieces->k &= notEndSquare;
        enemyPieces->q &= notEndSquare;
        enemyPieces->r &= notEndSquare;
        enemyPieces->b &= notEndSquare;
        enemyPieces->n &= notEndSquare;
        enemyPieces->p &= notEndSquare;
    }

    if(isPromo){ // if the move is a promo we have to add a new piece and remove the pawn from the end of the board
        
        *movedPiece &= ~endSquare; // first remove the pawn

        switch(misc){ // now based on the misc code add the piece we are promoting to

            case (uint16_t)0:
                friendlyPieces->n |= endSquare;
                break;
            case (uint16_t)1:
                friendlyPieces->b |= endSquare;
                break;
            case (uint16_t)2:
                friendlyPieces->r |= endSquare;
                break;
            case (uint16_t)3:
                friendlyPieces->q |= endSquare;
                break;
            default:
                break;

        }
    }

    return board;

}

void generateMovesWhite(BitBoard *board, Move *moves){

    // a board that simply has the position of all oponnent pieces
    uint64_t opBoard = board->black.k | board->black.q | board->black.r | board->black.b | board->black.n | board->black.p;
    // a board that contains all friendly pieces
    uint64_t myBoard = board->white.k | board->white.q | board->white.r | board->white.b | board->white.n | board->white.p;
    // a board that contains all pieces
    uint64_t wholeBoard = opBoard | myBoard;


    RawBoard friendlyPieces = board->white;
    RawBoard enemyPieces = board->black;

    int pos = 0; // where in the movelist to put moves

    /*
        check for pawn moves in 5 stages,
        first pawns that are on their staring square so we have to check for two squre moves,
        then check the 3rd and 4th ranks normal pawn moves and captures
        then check the 5th rank where en passant captures become possible
        then pawns that are on the 6th rank so we only check normal pawn moves
        then finally pawns that are on the 7th rank so we also generate promotions
    */
    int i = 8;
    for(; i < 16; i++){ // pawns on the 2nd rank
        if((1ull << i) & friendlyPieces.p){ // we found a pawn, generate its legal moves

            if((1ull << (i + 8)) & wholeBoard){ // there is a piece blocking the pawn it cannot move forward
                
            }

        }
    }


}

void generateMovesBlack(BitBoard *board, Move *moves){




    
}

void generateMoves(BitBoard *board, Move *moves){

    if(board->whiteToMove){
        generateMovesWhite(board, moves);
    }
    else{
        generateMovesBlack(board, moves);
    }


}
