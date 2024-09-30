#include <stdint.h>
#include "BitBoard.h"

static inline int_fast32_t material(BitBoard board){

    int_fast32_t mat = 0;

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


// the evaluation function must always return a positive value when the player whose turn it is, is doing well
// for now the evaluation function will simply be material
int_fast32_t evaluate(BitBoard board){

    int_fast32_t mat = material(board);

    
    return board.whiteToMove ? -mat : mat;

}


