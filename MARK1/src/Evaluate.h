#ifndef EVALUATE_H
#define EVALUATE_H

#include <stdint.h>
#include "BitBoard.h"

// the overall evaluation function
int64_t evaluate(BitBoard);

// returns the total value of black pieces minus the total value of black pieces
int_fast8_t material(BitBoard);





#endif