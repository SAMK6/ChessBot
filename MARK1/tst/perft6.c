#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/BitBoard.h"
#include "../src/Translator.h"
#include "../src/MoveGenerator.h"



uint64_t perft(BitBoard board, int depth){

    if(depth == 0) return 1ull;

    MoveBoard moves[256];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    uint64_t positions = 0ull;

    for(int i = 0; i < numMoves; i++){
        uint8_t kingPos = (uint8_t)__builtin_ctzll(moves[i].board.whiteToMove ? moves[i].board.black.k : moves[i].board.white.k);
        if(!isSquareAttacked(&(moves[i].board), kingPos)) positions += (depth == 1) ? 1 : perft(moves[i].board, depth - 1);
    }

    return positions;

}

int main(){

    char *FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard board = fenToBitBoard(FEN);

    uint64_t perftRes = perft(board, 6);

    printf("%lu\n", perftRes);

}