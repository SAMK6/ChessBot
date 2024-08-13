#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "BitBoard.h"


/*
    Moves will be from-to notation with 4 bits for extra info
    bits 0-5 are the start square, we can use these to bit shift and create the piece mask later
    bits 6-11 are the end square, 
    bit 12 represents whether or not the move is a capture
    bit 13 represents whethere the move is a promotion or not
    if bit 13 is set then bits 14-15 represent the piece the pawn is promoted to, 00 for knight, 01 for bishop, 10 for rook, 11 for queen
    if bit 13 is unset then bits 14-15 represent misc info, 00 for 

    the nullmove is all zeros

    I originally had this idea but didnt realise that bits 14-15 could still be used if the move is not a promotion,
    after reading CPW (https://www.chessprogramming.org/Encoding_Moves) I realised bits 14-15 could be used either way and 
    therefore my move representation is a simplified version of the table used in the article linked
*/


// gonna define masks to get specific parts of the move object
#define startMask 63 // first 6 bits (0-5)
#define endMask 4032 // second 6 bits (6-11)
#define isCaptureMask 4096 // 12th bit
#define isPromoMask 8192 // 13th bit
#define miscMask 49152 // final two bits

typedef unsigned short Move;

void generateMoves(BitBoard, Move*); // functions receives a board and a preallocated array for the moves to be put into

#endif