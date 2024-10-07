#ifndef SEARCH_H
#define SEARCH_H


#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"

#define NEG_INFINITY (INT32_MIN + 1)
#define POS_INFINITY INT32_MAX


int32_t quiescenceSearch(BitBoard*, int32_t, int32_t, uint64_t*);

int32_t search(BitBoard*, int, int32_t, int32_t, uint64_t*);

Move bestMove(BitBoard, int depth, uint64_t*);





#endif
