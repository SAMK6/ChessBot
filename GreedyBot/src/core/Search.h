#ifndef SEARCH_H
#define SEARCH_H


#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"


float quiescenceSearch(BitBoard*, float, float, uint64_t*);

float search(BitBoard*, int, float, float, uint64_t*);

Move bestMove(BitBoard, int depth, uint64_t*);





#endif
