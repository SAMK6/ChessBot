#include <stdint.h>
#include "BitBoard.h"

static inline int_fast32_t material(BitBoard board){

    int_fast32_t blackMat = 0, whiteMat = 0;;

    blackMat += __builtin_popcountll(board.black.p);
    blackMat += __builtin_popcountll(board.black.n) * 3;
    blackMat += __builtin_popcountll(board.black.b) * 3;
    blackMat += __builtin_popcountll(board.black.r) * 5;
    blackMat += __builtin_popcountll(board.black.q) * 9;

    whiteMat += __builtin_popcountll(board.white.p);
    whiteMat += __builtin_popcountll(board.white.n) * 3;
    whiteMat += __builtin_popcountll(board.white.b) * 3;
    whiteMat += __builtin_popcountll(board.white.r) * 5;
    whiteMat += __builtin_popcountll(board.white.q) * 9;

    return board.whiteToMove ? whiteMat - blackMat : blackMat - whiteMat;

}


// the evaluation function must always return a positive value when the player whose turn it is, is doing well
// for now the evaluation function will simply be material
int_fast32_t evaluate(BitBoard board){

    return material(board); 

}


