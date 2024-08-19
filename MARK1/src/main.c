#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"


int main(){


    char* fen = "r1bqkb1r/p1n1p1p1/2pn4/1p1p1p1p/1P1P1P1P/2P5/P1N1PNP1/R1BQKB1R w KQkq - 1 12";

    BitBoard board = fenToBitBoard(fen);

    debugPrintBitBoard(board);

    char* valid = validBitBoard(board) ? "valid" : "invalid";

    printf("\n%s\n", valid);

    char* myFen = malloc(100*sizeof(char));

    bitBoardToFen(board, myFen);

    printf("%s\n%s\n%d\n\n", myFen, fen, strcmp(myFen, fen));

    printBits16(startMask);
    printBits16(endMask);
    printBits16(isCaptureMask);
    printBits16(isPromoMask);
    printBits16(miscMask);

    printf("\n");

    printBitoard64(board.black.p);
    
    printf("\n");

    printBitoard64(generateKnightMask(F1num));

    printf("\n");



    return 0;

}