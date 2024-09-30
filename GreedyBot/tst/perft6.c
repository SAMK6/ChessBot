#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/BitBoard.h"
#include "../src/Translator.h"
#include "../src/MoveGenerator.h"



uint64_t perft(BitBoard board, int depth){

    if(depth == 0) return 1ull;

    Move moves[100];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);
    BitBoard newBoard;
    uint64_t positions = 0ull;

    for(int i = 0; i < numMoves; i++){
        
        newBoard = makeMove(board, moves[i]);
        uint8_t kingPos = (uint8_t)__builtin_ctzll(newBoard.whiteToMove ? newBoard.black.k : newBoard.white.k);
        if(!isSquareAttacked(&(newBoard), kingPos)) positions += (depth == 1) ? 1 : perft(newBoard, depth - 1);

    }
  
    return positions;

}

int main(){

    char *FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard board = fenToBitBoard(FEN);

    uint64_t perftRes = perft(board, 6);

    printf("%lu\n", perftRes);

}