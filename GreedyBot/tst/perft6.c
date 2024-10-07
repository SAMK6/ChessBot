#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/core/BitBoard.h"
#include "../src/core/Translator.h"
#include "../src/core/MoveGenerator.h"



uint64_t perft(BitBoard *board, int depth){

    Move moves[100];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    BitBoard newBoard;
    uint64_t positions = 0ull;

    for(int i = 0; i < numMoves; i++){

        newBoard = *board;
        makeMove(&newBoard, moves[i]);

        uint8_t kingPos = __builtin_ctzll(*((uint64_t*)&newBoard + 5 + 6 * !newBoard.whiteToMove));
        if(!isSquareAttacked(&newBoard, kingPos)) positions += (depth == 1) ? 1 : perft(&newBoard, depth - 1);

    }
  
    return positions;

}

int main(){

    char *FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard board = fenToBitBoard(FEN);

    uint64_t perftRes = perft(&board, 6);

    printf("%lu\n", perftRes);

}