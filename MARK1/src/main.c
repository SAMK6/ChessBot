#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"
#include "BitMasks.h"


int main(){


    char* fen = "rnbqkbnr/pppp1ppp/8/4p3/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";

    BitBoard board = fenToBitBoard(fen);

    debugPrintBitBoard(board);

    char* valid = validBitBoard(board) ? "valid" : "invalid";

    printf("\n%s\n", valid);

    char* myFen = malloc(100*sizeof(char));

    bitBoardToFen(board, myFen);

    printf("%s\n%s\n%d\n\n", myFen, fen, strcmp(myFen, fen));

    printf("startMask: ");
    printBits16(startMask);
    printf("endMask: ");
    printBits16(endMask);
    printf("captureMask: ");
    printBits16(isCaptureMask);
    printf("promoMask: ");
    printBits16(isPromoMask);
    printf("miscMask: ");
    printBits16(miscMask);
    printf("pieceMask: ");
    printBits16(pieceMask);

    printf("\n\n");

    Move move = ((uint16_t)0) | ((uint16_t)1 << 6) | ((uint16_t)0 << 12);

    char *movedFen = (char*)malloc(150*sizeof(char));

    BitBoard newBoard = makeMove(board, move, 'R');

    bitBoardToFen(newBoard, movedFen);

    printf("%s\n", movedFen);


    return 0;

}