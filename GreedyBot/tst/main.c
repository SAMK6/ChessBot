#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../src/core/BitBoard.h"
#include "../src/core/Translator.h"
#include "../src/core/MoveGenerator.h"
#include "../src/core/Magics.h"
#include "../src/core/Search.h"
#include "../src/generators/BitMasks.h"

static inline int whatPiece(BitBoard* board, uint64_t square){

    uint64_t* tricky = (uint64_t*)board;

    return (!!(*(tricky + 0) & square) * 0) + (!!(*(tricky + 1) & square) * 1) + (!!(*(tricky + 2) & square) * 2) + (!!(*(tricky + 3) & square) * 3) + (!!(*(tricky + 4) & square) * 4) + (!!(*(tricky + 5) & square) * 5) + (!!(*(tricky + 6) & square) * 6) + (!!(*(tricky + 7) & square) * 7) + (!!(*(tricky + 8) & square) * 8) + (!!(*(tricky + 9) & square) * 9) + (!!(*(tricky + 10) & square) * 10) + (!!(*(tricky + 11) & square) * 11);

}

static inline int myIndex(uint8_t a, uint8_t b){

    return (((a ^ ((a ^ b) & -((uint8_t)(a - b) >> 7))) * ((a ^ ((a ^ b) & -((uint8_t)(a - b) >> 7))) - 1)) >> 1) + (b ^ ((a ^ b) & -((uint8_t)(a - b) >> 7)));

}

static inline uint8_t min8(uint8_t a, uint8_t b) {
    return b ^ ((a ^ b) & -((uint8_t)(a - b) >> 7));
}

static inline uint8_t max8(uint8_t a, uint8_t b) {
    return a ^ ((a ^ b) & -((uint8_t)(a - b) >> 7));
}

int main(){

    char* startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard start = fenToBitBoard(startpos);

    printBoard(start);

    for(int i = 63; i >= 0; i--){

        if(i % 8 == 7) printf("\n");

        printf("%3d", whatPiece(&start, 1ull << i));

    }

    printf("\n");

    char* fen = "r3k2r/ppbn1pp1/2pqp1bp/3pNn2/3P1P2/P2BP2P/1PPBN1P1/R2Q1RK1 b kq - 2 13";

    BitBoard board = fenToBitBoard(fen);

    printBoard(board);

    debugPrintBitBoard(board);

    char* valid = validBitBoard(board) ? "valid" : "invalid";

    printf("\n%s\n", valid);

    char* myFen = malloc(100*sizeof(char));

    bitBoardToFen(board, myFen);

    printf("%s\n%s\n%d\n\n", myFen, fen, strcmp(myFen, fen));

    printf("startMask: ");
    printBits32(startMask);
    printf("endMask: ");
    printBits32(endMask);
    printf("captureMask: ");
    printBits32(isCaptureMask);
    printf("promoMask: ");
    printBits32(isPromoMask);
    printf("miscMask: ");
    printBits32(miscMask);
    printf("pieceMask: ");
    printBits32(pieceMask);
    printf("white Kingside castle\n");
    printBitBoard64(whiteKingsideCastle);
    printf("white queenside castle\n");
    printBitBoard64(whiteQueensideCastle);
    printf("black kingside castle\n");
    printBitBoard64(blackKingsideCastle);
    printf("black queenside castle\n");
    printBitBoard64(blackQueensideCastle);
    printf("\n\n");




    return 0;

}