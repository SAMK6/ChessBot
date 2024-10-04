#include <stdio.h>
#include <stdint.h>
#include "BitBoard.h"
#include "Magics.h"


int validBitBoard(BitBoard board){ // this function is now a full check but rather some general sanity checks

    // first check is since there cannot be two peices on one squre the bitwise and of all the piece boards should be 0
    uint64_t check = board.white.k & board.white.q & board.white.r & board.white.b & board.white.n & board.white.p & board.black.k & board.black.q & board.black.r & board.black.b & board.black.n & board.black.p;
    if(check){
        return 0;
    }

    // next we can check that if there is an en passant square there must be a pawn in front of it
    // and depending on which peice can be captured en passant we check it is the correct players turn
    if(board.enPassant){

        if(__builtin_popcountll(board.enPassant) > 1){
            return 0; // only 1 bit should ever be set
        }

        uint64_t pawn;
        if(board.enPassant > A5 && board.enPassant < H7){ // black pawn can be captured en passant
            pawn = board.enPassant >> 8;

            if(!((pawn & board.black.p) == pawn) || !board.whiteToMove){
                return 0;
            }
        }
        else if(board.enPassant > A2 && board.enPassant < H4){ // white pawn can be captured en passant
            pawn = board.enPassant << 8;

            if(!((pawn & board.white.p) == pawn) || board.whiteToMove){
                return 0;
            }
        }
        else{
            return 0; // invalid en passant squre
        }
    }

    // finally we can check that if castling is allowed the rooks and kings are in the proper position
    if(board.castling){

        if(board.castling & (uint16_t)8){ // white can castle kingside
            if(!((board.white.k & E1) && (board.white.r & H1))){
                return 0;
            }
        }
        if(board.castling & (uint16_t)4){ // white can castle queenside
            if(!((board.white.k & E1) && (board.white.r & A1))){
                return 0;
            }
        }
        if(board.castling & (uint16_t)2){ // black can castle kingside
            if(!((board.black.k & E8) && (board.black.r & H8))){
                return 0;
            }
        }
        if(board.castling & (uint16_t)1){ // black can castle queenside
            if(!((board.black.k & E8) && (board.black.r & A8))){
                return 0;
            }
        }


    }


    return 1;

}

// function that checks if square can be attacked by the player whose turn it is
int isSquareAttacked(BitBoard *board, uint8_t square){

    RawBoard *friendlyPieces = ((RawBoard*)board + board->whiteToMove);
    uint64_t wholeBoard = board->white.p | board->white.n | board->white.b | board->white.r | board->white.q | board->white.k | board->black.p | board->black.n | board->black.b | board->black.r | board->black.q | board->black.k;
    
    uint64_t bishopAttacks = getBishopAttacks(square, wholeBoard), rookAttacks = getRookAttacks(square, wholeBoard), pawnAttacks = board->whiteToMove ? basicPawnMasksBlack[square] : basicPawnMasksWhite[square];

    return ((rookAttacks | bishopAttacks) & friendlyPieces->q) || (rookAttacks & friendlyPieces->r) || (bishopAttacks & friendlyPieces->b) || (basicKnightMasks[square] & friendlyPieces->n) || (pawnAttacks & friendlyPieces->p) || (basicKingMasks[square] & friendlyPieces->k);

}


void printBits8(uint8_t tar){

    uint8_t mask = (uint8_t)1 << 7;

    for(int i = 0; i < 8; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}

void printBits16(uint16_t tar){

    uint16_t mask = (uint16_t)1 << 15;

    for(int i = 0; i < 16; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}


void printBits32(uint32_t tar){

    uint32_t mask = (uint32_t)1 << 31;

    for(int i = 0; i < 32; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}


void printBits64(uint64_t tar){
    uint64_t mask = (uint64_t)1 << 63;

    for(int i = 0; i < 64; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}

void printBitBoard64(uint64_t tar){
    uint64_t mask = (uint64_t)1 << 63;

    for(int i = 0; i < 64; i++){
        if(i>0 && i%8 == 0){
            printf("\n");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n\n");
}




// uses printBits to show a whole bitboard, also for debugging and visualization
void debugPrintBitBoard(BitBoard board){

    printf("white King:\n");
    printBitBoard64(board.white.k);

    printf("white Queen:\n");
    printBitBoard64(board.white.q);

    printf("white Rooks:\n");
    printBitBoard64(board.white.r);

    printf("white Bishops:\n");
    printBitBoard64(board.white.b);

    printf("white Knights:\n");
    printBitBoard64(board.white.n);

    printf("white Pawns:\n");
    printBitBoard64(board.white.p);


    printf("\n");


    printf("black King:\n");
    printBitBoard64(board.black.k);

    printf("black Queen:\n");
    printBitBoard64(board.black.q);

    printf("black Rooks:\n");
    printBitBoard64(board.black.r);

    printf("black Bishops:\n");
    printBitBoard64(board.black.b);

    printf("black Knights:\n");
    printBitBoard64(board.black.n);

    printf("black Pawns:\n");
    printBitBoard64(board.black.p);


    printf("\n");


    printf("whiteToMove:\n");
    printBits8(board.whiteToMove);

    printf("castling:\n");
    printBits8(board.castling);

    printf("halfMoves: %d\n", board.halfMoves);
    printBits8(board.halfMoves);

    printf("moves: %d\n", board.moves);
    printBits16(board.moves);

    printf("enPassant:\n");
    printBitBoard64(board.enPassant);

}