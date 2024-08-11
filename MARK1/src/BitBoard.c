#include <stdio.h>
#include "BitBoard.h"


int validBitBoard(BitBoard board){

    // first check is since there cannot be two peices on one squre the bitwise and of all the piece boards should be 0
    Bint check = board.K & board.Q & board.R & board.B & board.N & board.P & board.k & board.q & board.r & board.b & board.n & board.p;
    if(check){
        return 0;
    }

    // next we can check that if there is an en passant square there must be a pawn in front of it
    // and depending on which peice can be captured en passant we check it is the correct players turn
    if(board.enPassant){

        Bint pawn;
        if(board.enPassant > 2147483648ull){ // black pawn can be captured en passant
            pawn = board.enPassant >> 8;

            if(!((pawn & board.p) == pawn) || !board.whiteToMove){
                return 0;
            }
        }
        else{ // white pawn can be captured en passant
            pawn = board.enPassant << 8;

            if(!((pawn & board.P) == pawn) || board.whiteToMove){
                return 0;
            }
        }
    }

    // finally we can check that if castling is allowed the rooks and kings are in the proper position
    if(board.castling){

        if(board.castling & (unsigned short)8){ // white can castle kingside
            if(!((board.K & 8ull) && (board.R & 1ull))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)4){ // white can castle queenside
            if(!((board.K & 8ull) && (board.R & 128ull))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)2){ // black can castle kingside
            if(!((board.k & 576460752303423488ull) && (board.r & 72057594037927936ull))){
                return 0;
            }
        }
        if(board.castling & (unsigned short)1){ // black can castle queenside
            if(!((board.k & 576460752303423488ull) && (board.r & 9223372036854775808ull))){
                return 0;
            }
        }


    }


    return 1;

}


// basic function to print the bits of any data, needs correct number of bits as input or will crash, for debugging
void printBits(void* target, int numBits){

    if(numBits == 8){
        unsigned char tar = *(unsigned char*)target;
        unsigned char mask = (unsigned char)1 << 7;

        for(int i = 0; i < 8; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&tar));
            tar = tar<<1;
        }
    }
    else if(numBits == 16){
        unsigned short tar = *(unsigned short*)target;
        unsigned short mask = (unsigned short)1 << 15;

        for(int i = 0; i < 16; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&tar));
            tar = tar<<1;
        }
    }
    else if(numBits == 32){
        unsigned int tar = *(unsigned int*)target;
        unsigned int mask = (unsigned int)1 << 31;

        for(int i = 0; i < 32; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&tar));
            tar = tar<<1;
        }
    }
    else if(numBits == 64){
        unsigned long tar = *(unsigned long*)target;
        unsigned long mask = (unsigned long)1 << 63;

        for(int i = 0; i < 64; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&tar));
            tar = tar<<1;
        }
    }

    printf("\n");

}


// uses printBits to show a whole bitboard, also for debugging and visualization
void debugPrintBitBoard(BitBoard board){

    printf("white King:\n");
    printBits(&(board.K), 64);

    printf("white Queen:\n");
    printBits(&(board.Q), 64);

    printf("white Rooks:\n");
    printBits(&(board.R), 64);

    printf("white Bishops:\n");
    printBits(&(board.B), 64);

    printf("white Knights:\n");
    printBits(&(board.N), 64);

    printf("white Pawns:\n");
    printBits(&(board.P), 64);


    printf("\n");


    printf("black King:\n");
    printBits(&(board.k), 64);

    printf("black Queen:\n");
    printBits(&(board.q), 64);

    printf("black Rooks:\n");
    printBits(&(board.r), 64);

    printf("black Bishops:\n");
    printBits(&(board.b), 64);

    printf("black Knights:\n");
    printBits(&(board.n), 64);

    printf("black Pawns:\n");
    printBits(&(board.p), 64);


    printf("\n");


    printf("whiteToMove:\n");
    printBits(&(board.whiteToMove), 8);

    printf("castling:\n");
    printBits(&(board.castling), 8);

    printf("halfMoves: %d\n", board.halfMoves);
    printBits(&(board.halfMoves), 8);

    printf("moves: %d\n", board.moves);
    printBits(&(board.moves), 16);

    printf("enPassant:\n");
    printBits(&(board.enPassant), 64);

}