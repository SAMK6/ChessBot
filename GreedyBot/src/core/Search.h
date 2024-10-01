#ifndef SEARCH_H
#define SEARCH_H


#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"

typedef struct SearchResult{

    int_fast32_t evaluation;
    Move bestMove;

} SearchResult;


SearchResult search(BitBoard, int);



#endif
