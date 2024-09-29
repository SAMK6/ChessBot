#include <stdint.h>
#include "BitBoard.h"


// for now the evaluation function will simply be material and a crude estimation of space
int64_t evaluate(BitBoard board){

    return material(board);

}



inline int_fast8_t material(BitBoard board){

    int_fast8_t mat = 0;

    mat += __builtin_popcountll(board.black.p);
    mat += __builtin_popcountll(board.black.n) * 3;
    mat += __builtin_popcountll(board.black.b) * 3;
    mat += __builtin_popcountll(board.black.r) * 5;
    mat += __builtin_popcountll(board.black.q) * 9;

    mat -= __builtin_popcountll(board.white.p);
    mat -= __builtin_popcountll(board.white.n) * 3;
    mat -= __builtin_popcountll(board.white.b) * 3;
    mat -= __builtin_popcountll(board.white.r) * 5;
    mat -= __builtin_popcountll(board.white.q) * 9;

    return mat;

}