#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"
#include "BitMasks.h"


int main(){


    char* fen = "r2r2k1/pp2bpp1/2q1pn1p/6B1/8/2P5/PP2QPPP/1B1R1RK1 w - - 0 17";

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

    printf("\n\n");

    uint64_t allPieces = board.black.k | board.black.q | board.black.r | board.black.b | board.black.n | board.black.p | board.white.k | board.white.q | board.white.r | board.white.b | board.white.n | board.white.p;

    printBitBoard64(allPieces);

    uint64_t attacks = generateBishopAttacks(D2num, allPieces);

    printBitBoard64(attacks);


    return 0;

}