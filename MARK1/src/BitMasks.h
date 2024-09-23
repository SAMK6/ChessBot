#ifndef BITMASKS_H
#define BITMASKS_H

#include <stdint.h>

// might have to take extern away later for speed but for now it's needed for testing etc
extern uint64_t basicKnightMasks[64];
extern uint64_t basicBishopMasks[64];
extern uint64_t basicRookMasks[64];
extern uint64_t basicKingMasks[64];

uint64_t generateRookMask(uint8_t);
uint64_t generateBishopMask(uint8_t);
uint64_t generateKnightMask(uint8_t);
uint64_t generateQueenMask(uint8_t);
uint64_t generateKingMask(uint8_t);

uint64_t generateBishopAttacks(uint8_t, uint64_t);
uint64_t generateRookAttacks(uint8_t, uint64_t);


#endif