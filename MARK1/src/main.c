#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "BitBoard.h"
#include "Translator.h"
#include "MoveGenerator.h"
#include "BitMasks.h"


int main(){


    char* fen = "r5k1/1P3pp1/8/7p/8/8/6KP/r2R4 w - - 0 36";

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
    printf("white Kingside castle\n");
    printBitBoard64(whiteKingsideCastle);
    printf("white queenside castle\n");
    printBitBoard64(whiteQueensideCastle);
    printf("black kingside castle\n");
    printBitBoard64(blackKingsideCastle);
    printf("black queenside castle\n");
    printBitBoard64(blackQueensideCastle);
    printf("\n\n");

    Move move = buildMove(59,57,2);

    char *movedFen = (char*)malloc(300 *sizeof(char));

    BitBoard newBoard = makeMove(board, move, 'k');

    bitBoardToFen(newBoard, movedFen);

    printf("%s\n", movedFen);




    MoveBoard *moves = (MoveBoard*)malloc(100 * sizeof(MoveBoard));

    int numMoves = generateMovesWhite(&board, moves);

    int actualTotal = numMoves;

    MoveBoard position;
    for(int i = 0; i < numMoves; i++){

        position = *(moves + i);
        position.board.whiteToMove = 0;

        uint64_t king = position.board.white.k;
        uint8_t kingPos = __builtin_ctzll(king);

        if(isSquareAttacked(&(position.board), kingPos)){
            actualTotal--;
        }
        else{
            uint16_t from = position.move & startMask, to = (position.move & endMask) >> 6;
            printf("from: %d\nto: %d\n\n", from, to);
        }



    }

    printf("%d\n", actualTotal);


    return 0;

}