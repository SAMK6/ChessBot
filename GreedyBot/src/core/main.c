#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"
#include "Magics.h"


int main(){


    char* fen = "r3k2r/ppbn1pp1/2pqp1bp/3pNn2/3P1P2/P2BP2P/1PPBN1P1/R2Q1RK1 b kq - 2 13";

    BitBoard board = fenToBitBoard(fen);

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




    Move *moves = (Move*)malloc(1000 * sizeof(Move));

    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    int actualTotal = numMoves;
    BitBoard position = board;

    for(int i = 0; i < numMoves; i++){

        position = board;
        
        makeMove(&position, *(moves + i));

        uint64_t king = position.whiteToMove ? position.black.k : position.white.k;
        uint8_t kingPos = __builtin_ctzll(king);

        if(isSquareAttacked(&position, kingPos)){
            actualTotal--;
        }
        else{
            uint16_t from = *(moves + i) & startMask, to = (*(moves + i) & endMask) >> 6;
            printf("from: %d\nto: %d\n\n", from, to);
        }

    }

    return 0;

}