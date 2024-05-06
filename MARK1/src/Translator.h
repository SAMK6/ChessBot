#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "BitBoard.h"

// takes in a FEN string, creates amd returns the coresspoding bitboards
// fen string must be null terminated, other formats will casue issues
BitBoard fenToBitBoard(const char*);

// takes in a bitBoard and turns it into a FEN string, pass in a dynamically alocated char array of size n and the null terminated FEN string is placed there
void bitBoardToFen(BitBoard, char*);

#endif