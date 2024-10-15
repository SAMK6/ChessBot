#ifndef MAGICS_H
#define MAGICS_H

#include <stdint.h>

#define getRookAttacks(square_num, _blockers) (magic_rookTable[((((_blockers) & basicRookMasks[square_num]) * rookMagics[square_num]) >> magic_rookShifts[square_num]) + magic_rookOffSets[square_num]])

#define getBishopAttacks(square_num, _blockers) (magic_bishopTable[((((_blockers) & basicBishopMasks[square_num]) * bishopMagics[square_num]) >> magic_bishopShifts[square_num]) + magic_bishopOffSets[square_num]])

#define getLineMask(square_1, square_2) (basicPinMasks[(((square_1 ^ ((square_1 ^ square_2) & -((uint8_t)(square_1 - square_2) >> 7))) * ((square_1 ^ ((square_1 ^ square_2) & -((uint8_t)(square_1 - square_2) >> 7))) - 1)) >> 1) + (square_2 ^ ((square_1 ^ square_2) & -((uint8_t)(square_1 - square_2) >> 7)))])

extern const uint64_t basicKnightMasks[64];
extern const uint64_t basicBishopMasks[64];
extern const uint64_t basicRookMasks[64];
extern const uint64_t basicKingMasks[64];
extern const uint64_t basicPawnMasksBlack[64];
extern const uint64_t basicPawnMasksWhite[64];

extern const uint64_t basicPinMasks[2016];

extern const uint64_t bishopMagics[64];
extern const uint64_t rookMagics[64];

extern const int magic_bishopOffSets[64];
extern const int magic_rookOffSets[64];

extern const int magic_bishopShifts[64];
extern const int magic_rookShifts[64];

extern const uint64_t magic_bishopTable[5248];
extern const uint64_t magic_rookTable[102400];


#endif