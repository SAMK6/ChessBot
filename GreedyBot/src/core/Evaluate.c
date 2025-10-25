#include <stdint.h>
#include "BitBoard.h"

static inline float material(const BitBoard *board){

    float blackMat = 0, whiteMat = 0;;

    blackMat += (float)__builtin_popcountll(board->black.p);
    blackMat += (float)__builtin_popcountll(board->black.n) * 3.0;
    blackMat += (float)__builtin_popcountll(board->black.b) * 3.0;
    blackMat += (float)__builtin_popcountll(board->black.r) * 5.0;
    blackMat += (float)__builtin_popcountll(board->black.q) * 9.0;

    whiteMat += (float)__builtin_popcountll(board->white.p);
    whiteMat += (float)__builtin_popcountll(board->white.n) * 3.0;
    whiteMat += (float)__builtin_popcountll(board->white.b) * 3.0;
    whiteMat += (float)__builtin_popcountll(board->white.r) * 5.0;
    whiteMat += (float)__builtin_popcountll(board->white.q) * 9.0;

    return board->whiteToMove ? whiteMat - blackMat : blackMat - whiteMat;

}


// the evaluation function must always return a positive value when the player whose turn it is, is doing well
// for now the evaluation function will simply be material
float evaluate(const BitBoard *board){

    return material(board); 

}


