#ifndef SEARCH_H
#define SEARCH_H


#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"

int_fast32_t search(BitBoard*, int);

Move bestMove(BitBoard);



#endif
