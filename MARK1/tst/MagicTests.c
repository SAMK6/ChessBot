#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../src/Translator.h"
#include "../src/BitBoard.h"
#include "../src/Magics.h"
#include "../src/BitMasks.h"

int main(){

    int wrong = 0;


    char *FEN = "r3kb1r/pb2qppp/1pp2n2/3p4/3N4/8/PPP2PPP/RNBQR1K1 b kq - 1 11";
    BitBoard board = fenToBitBoard(FEN);
    uint64_t wholeBoard = board.white.p | board.white.n | board.white.b | board.white.r | board.white.q | board.white.k | board.black.p | board.black.n | board.black.b | board.black.r | board.black.q | board.black.k;
    
    
    for(int i = 0; i < 64; i++){
        uint64_t blockers = wholeBoard & basicRookMasks[i];

        if(generateRookAttacks(i, blockers) != getRookAttacks(i, blockers)){
            printf("error with position: %s\nsquare: %d\n", FEN, i);
            printBitBoard64(generateRookAttacks(i, blockers));
            printBitBoard64(getRookAttacks(i, blockers));
            wrong++;
        }

    }

    FEN = "6r1/pk6/1p6/2p1Np1p/7P/1P6/r4PK1/4R3 w - - 2 36";
    board = fenToBitBoard(FEN);
    wholeBoard = board.white.p | board.white.n | board.white.b | board.white.r | board.white.q | board.white.k | board.black.p | board.black.n | board.black.b | board.black.r | board.black.q | board.black.k;

    for(int i = 0; i < 64; i++){
        uint64_t blockers = wholeBoard & basicRookMasks[i];

        if(generateRookAttacks(i, blockers) != getRookAttacks(i, blockers)){
            printf("error with position: %s\nsquare: %d\n", FEN, i);
            printBitBoard64(generateRookAttacks(i, blockers));
            printBitBoard64(getRookAttacks(i, blockers));
            wrong++;
        }

    }

    FEN = "5rk1/5pp1/rpp1p1P1/7p/3P3P/p1q5/P1B5/2K3RR b - - 0 28";
    board = fenToBitBoard(FEN);
    wholeBoard = board.white.p | board.white.n | board.white.b | board.white.r | board.white.q | board.white.k | board.black.p | board.black.n | board.black.b | board.black.r | board.black.q | board.black.k;

    for(int i = 0; i < 64; i++){
        uint64_t blockers = wholeBoard & basicRookMasks[i];

        if(generateRookAttacks(i, blockers) != getRookAttacks(i, blockers)){
            printf("error with position: %s\nsquare: %d\n", FEN, i);
            printBitBoard64(generateRookAttacks(i, blockers));
            printBitBoard64(getRookAttacks(i, blockers));
            wrong++;
        }

    }

    printf("wrong: %d\n", wrong);



}