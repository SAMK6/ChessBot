#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"


int main(){


    char* fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

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

    return 0;

}