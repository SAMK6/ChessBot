#include <stdio.h>
#include <stdlib.h>
#include "../src/BitMasks.h"


int main(int argc, int** argv){

    int knightFails = 0, bishopFails = 0, rookFails = 0, kingFails = 0;


    for(uint8_t i = 0; i < 64; i++){

        if(!(generateKnightMask(i) == basicKnightMasks[i])){
            knightFails++;
            printf("Knight mask test failed for square: %d\n", i);
        }

    }

    for(uint8_t i = 0; i < 64; i++){

        if(!(generateBishopMask(i) == basicBishopMasks[i])){
            bishopFails++;
            printf("Knight mask test failed for square: %d\n", i);
        }

    }

    for(uint8_t i = 0; i < 64; i++){

        if(!(generateRookMask(i) == basicRookMasks[i])){
            rookFails++;
            printf("rook mask test failed for square: %d\n", i);
        }

    }

    for(uint8_t i = 0; i < 64; i++){

        if(!(generateKingMask(i) == basicKingMasks[i])){
            kingFails++;
            printf("King mask test failed for square: %d\n", i);
        }

    }

    printf("Knight fails: %d\nBishop fails: %d\nRook fails: %d\nKing fails: %d\n", knightFails, bishopFails, rookFails, kingFails);


}