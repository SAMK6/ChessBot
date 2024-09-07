#ifndef BITMASKS_H
#define BITMASKS_H

#include <stdint.h>


uint64_t generateRookMask(uint8_t);
uint64_t generateBishopMask(uint8_t);
uint64_t generateKnightMask(uint8_t);
uint64_t generateQueenMask(uint8_t);
uint64_t generateKingMask(uint8_t);

uint64_t generateBishopAttacks(uint8_t, uint64_t);
uint64_t generateRookAttacks(uint8_t, uint64_t);


#endif