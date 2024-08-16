#include <stdio.h>
#include "BitBoard.h"


int validBitBoard(BitBoard board){ // this function is now a full check but rather some general sanity checks

    // first check is since there cannot be two peices on one squre the bitwise and of all the piece boards should be 0
    Bint check = board.white.k & board.white.q & board.white.r & board.white.b & board.white.n & board.white.p & board.black.k & board.black.q & board.black.r & board.black.b & board.black.n & board.black.p;
    if(check){
        return 0;
    }

    // next we can check that if there is an en passant square there must be a pawn in front of it
    // and depending on which peice can be captured en passant we check it is the correct players turn
    if(board.enPassant){

        if(popcount64(board.enPassant) > 1){
            return 0; // only 1 bit should ever be set
        }

        Bint pawn;
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

        if(board.castling & (unsigned short)8){ // white can castle kingside
            if(!((board.white.k & E1) && (board.white.r & H1))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)4){ // white can castle queenside
            if(!((board.white.k & E1) && (board.white.r & A1))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)2){ // black can castle kingside
            if(!((board.black.k & E8) && (board.black.r & H8))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)1){ // black can castle queenside
            if(!((board.black.k & E8) && (board.black.r & A8))){
                return 0;
            }
        }


    }


    return 1;

}




void printBits8(unsigned char tar){

    unsigned char mask = (unsigned char)1 << 7;

    for(int i = 0; i < 8; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}

void printBits16(unsigned short tar){

    unsigned short mask = (unsigned short)1 << 15;

    for(int i = 0; i < 16; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}


void printBits32(unsigned int tar){

    unsigned int mask = (unsigned int)1 << 31;

    for(int i = 0; i < 32; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}


void printBits64(unsigned long tar){
    unsigned long mask = (unsigned long)1 << 63;

    for(int i = 0; i < 64; i++){
        if(i>0 && i%8 == 0){
            printf(" ");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}

void printBitoard64(unsigned long tar){
    unsigned long mask = (unsigned long)1 << 63;

    for(int i = 0; i < 64; i++){
        if(i>0 && i%8 == 0){
            printf("\n");
        }
        printf("%u", !!(mask&tar));
        tar = tar<<1;
    }

    printf("\n");
}




// uses printBits to show a whole bitboard, also for debugging and visualization
void debugPrintBitBoard(BitBoard board){

    printf("white King:\n");
    printBits64(board.white.k);

    printf("white Queen:\n");
    printBits64(board.white.q);

    printf("white Rooks:\n");
    printBits64(board.white.r);

    printf("white Bishops:\n");
    printBits64(board.white.b);

    printf("white Knights:\n");
    printBits64(board.white.n);

    printf("white Pawns:\n");
    printBits64(board.white.p);


    printf("\n");


    printf("black King:\n");
    printBits64(board.black.k);

    printf("black Queen:\n");
    printBits64(board.black.q);

    printf("black Rooks:\n");
    printBits64(board.black.r);

    printf("black Bishops:\n");
    printBits64(board.black.b);

    printf("black Knights:\n");
    printBits64(board.black.n);

    printf("black Pawns:\n");
    printBits64(board.black.p);


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
    printBits64(board.enPassant);

}


int popcount8(unsigned char n){

    n = (n & 0x55) + ((n >> 1) & 0x55);
    n = (n & 0x33) + ((n >> 2) & 0x33);
    n = (n & 0x0F) + ((n >> 4) & 0x0F);
    return (int)n;

}

int popcount16(unsigned short n){

    n = (n & 0x5555) + ((n >> 1) & 0x5555);
    n = (n & 0x3333) + ((n >> 2) & 0x3333);
    n = (n & 0x0F0F) + ((n >> 4) & 0x0F0F);
    n = (n & 0x00FF) + ((n >> 8) & 0x00FF);
    return(int)n;

}

int popcount32(unsigned int n){

    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
    n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
    return(int)n;

}

int popcount64(unsigned long n){

    n = (n & 0x5555555555555555) + ((n >> 1) & 0x5555555555555555);
    n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
    n = (n & 0x0F0F0F0F0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F0F0F0F0F);
    n = (n & 0x00FF00FF00FF00FF) + ((n >> 8) & 0x00FF00FF00FF00FF);
    n = (n & 0x0000FFFF0000FFFF) + ((n >> 16) & 0x0000FFFF0000FFFF);
    n = (n & 0x00000000FFFFFFFF) + ((n >> 32) & 0x00000000FFFFFFFF);
    return(int)n;

}