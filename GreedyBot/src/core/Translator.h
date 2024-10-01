#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <stdint.h>
#include "MoveGenerator.h"
#include "BitBoard.h"

// see https://www.chessprogramming.org/Forsyth-Edwards_Notation for info on FEN notation

// takes in a FEN string, creates amd returns the coresspoding bitboards
// fen string must be null terminated, other formats will casue issues
BitBoard fenToBitBoard(const char*);

// takes in a bitBoard and turns it into a FEN string, pass in a dynamically alocated char array of size n and the null terminated FEN string is placed there
void bitBoardToFen(BitBoard, char*);

void moveToUCI(Move, char*);


#endif