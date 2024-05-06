#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Translator.h"

void printBits(void* target, int numBits){

    if(numBits == 8){
        unsigned char* tar = (unsigned char*)target;
        unsigned char mask = (unsigned char)1 << 7;

        for(int i = 0; i < 8; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&*tar));
            *tar = *tar<<1;
        }
    }
    else if(numBits == 16){
        unsigned short* tar = (unsigned short*)target;
        unsigned short mask = (unsigned short)1 << 15;

        for(int i = 0; i < 16; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&*tar));
            *tar = *tar<<1;
        }
    }
    else if(numBits == 32){
        unsigned int* tar = (unsigned int*)target;
        unsigned int mask = (unsigned int)1 << 31;

        for(int i = 0; i < 32; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&*tar));
            *tar = *tar<<1;
        }
    }
    else if(numBits == 64){
        unsigned long* tar = (unsigned long*)target;
        unsigned long mask = (unsigned long)1 << 63;

        for(int i = 0; i < 64; i++){
            if(i>0 && i%8 == 0){
                printf(" ");
            }
            printf("%u", !!(mask&*tar));
            *tar = *tar<<1;
        }
    }

    printf("\n");

}

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

    printf("halfMoves:\n");
    printBits(&(board.halfMoves), 8);

    printf("moves:\n");
    printBits(&(board.moves), 16);



    printf("enPassant:\n");
    printBits(&(board.enPassant), 64);


}

int main(int argc, char** argv){


    char* fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

    BitBoard board = fenToBitBoard(fen);

    debugPrintBitBoard(board);


    return 0;

}