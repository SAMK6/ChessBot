#ifndef SEARCH_H
#define SEARCH_H


#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"

#define NEG_INFINITY (INT_FAST32_MIN + 1)
#define POS_INFINITY INT_FAST32_MAX


int_fast32_t quiescenceSearch(BitBoard*, int_fast32_t, int_fast32_t);

int_fast32_t search(BitBoard*, int, int_fast32_t, int_fast32_t);

Move bestMove(BitBoard);





#endif
