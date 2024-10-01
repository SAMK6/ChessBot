#ifndef MAGICS_H
#define MAGICS_H

#include <stdint.h>

#define getRookAttacks(squareNum, blockers) (magic_rookTable[(((blockers & basicRookMasks[squareNum]) * rookMagics[squareNum]) >> magic_rookShifts[squareNum]) + magic_rookOffSets[squareNum]])

#define getBishopAttacks(squareNum, blockers) (magic_bishopTable[(((blockers & basicBishopMasks[squareNum]) * bishopMagics[squareNum]) >> magic_bishopShifts[squareNum]) + magic_bishopOffSets[squareNum]])

extern const uint64_t basicKnightMasks[64];
extern const uint64_t basicBishopMasks[64];
extern const uint64_t basicRookMasks[64];
extern const uint64_t basicKingMasks[64];
extern const uint64_t basicPawnMasksBlack[64];
extern const uint64_t basicPawnMasksWhite[64];

extern const uint64_t bishopMagics[64];
extern const uint64_t rookMagics[64];

extern const int magic_bishopOffSets[64];
extern const int magic_rookOffSets[64];

extern const int magic_bishopShifts[64];
extern const int magic_rookShifts[64];

extern const uint64_t magic_bishopTable[5248];
extern const uint64_t magic_rookTable[102400];


#endif