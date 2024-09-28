#ifndef BITMASKS_H
#define BITMASKS_H

#include <stdint.h>

// might have to take extern away later for speed but for now it's needed for testing etc
extern const uint64_t basicKnightMasks[64];
extern const uint64_t basicBishopMasks[64];
extern const uint64_t basicRookMasks[64];
extern const uint64_t basicKingMasks[64];
extern const uint64_t basicPawnMasksBlack[64];
extern const uint64_t basicPawnMasksWhite[64];

// these functions generate a mask of possible squares a piece could go to
// assumes an empty board and takes a number 0-63 as input starting square
uint64_t generateRookMask(uint8_t);
uint64_t generateBishopMask(uint8_t);
uint64_t generateKnightMask(uint8_t);
uint64_t generateQueenMask(uint8_t);
uint64_t generateKingMask(uint8_t);
uint64_t generatePawnMaskWhite(uint8_t);
uint64_t generatePawnMaskBlack(uint8_t);

// these functions generate attacked squares for sliding pieces given a board state
// pass in the square (0-63) and the blockers all squares occupied by all pieces in a uint64_t
uint64_t generateBishopAttacks(uint8_t, uint64_t);
uint64_t generateRookAttacks(uint8_t, uint64_t);


#endif