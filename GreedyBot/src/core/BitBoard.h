#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>


// define all the "squares"
// if this part seems unclear take a look at bitboardtest.c and it will become more clear
#define H1 1ull
#define G1 2ull
#define F1 4ull
#define E1 8ull
#define D1 16ull
#define C1 32ull
#define B1 64ull
#define A1 128ull

#define H2 256ull
#define G2 512ull
#define F2 1024ull
#define E2 2048ull
#define D2 4096ull
#define C2 8192ull
#define B2 16384ull
#define A2 32768ull

#define H3 65536ull
#define G3 131072ull
#define F3 262144ull
#define E3 524288ull
#define D3 1048576ull
#define C3 2097152ull
#define B3 4194304ull
#define A3 8388608ull

#define H4 16777216ull
#define G4 33554432ull
#define F4 67108864ull
#define E4 134217728ull
#define D4 268435456ull
#define C4 536870912ull
#define B4 1073741824ull
#define A4 2147483648ull

#define H5 4294967296ull
#define G5 8589934592ull
#define F5 17179869184ull
#define E5 34359738368ull
#define D5 68719476736ull
#define C5 137438953472ull
#define B5 274877906944ull
#define A5 549755813888ull

#define H6 1099511627776ull
#define G6 2199023255552ull
#define F6 4398046511104ull
#define E6 8796093022208ull
#define D6 17592186044416ull
#define C6 35184372088832ull
#define B6 70368744177664ull
#define A6 140737488355328ull

#define H7 281474976710656ull
#define G7 562949953421312ull
#define F7 1125899906842624ull
#define E7 2251799813685248ull
#define D7 4503599627370496ull
#define C7 9007199254740992ull
#define B7 18014398509481984ull
#define A7 36028797018963968ull

#define H8 72057594037927936ull
#define G8 144115188075855872ull
#define F8 288230376151711744ull
#define E8 576460752303423488ull
#define D8 1152921504606846976ull
#define C8 2305843009213693952ull
#define B8 4611686018427387904ull
#define A8 9223372036854775808ull

// define all the square numbers

#define H1num ((uint8_t)0)
#define G1num ((uint8_t)1)
#define F1num ((uint8_t)2)
#define E1num ((uint8_t)3)
#define D1num ((uint8_t)4)
#define C1num ((uint8_t)5)
#define B1num ((uint8_t)6)
#define A1num ((uint8_t)7)

#define H2num ((uint8_t)8)
#define G2num ((uint8_t)9)
#define F2num ((uint8_t)10)
#define E2num ((uint8_t)11)
#define D2num ((uint8_t)12)
#define C2num ((uint8_t)13)
#define B2num ((uint8_t)14)
#define A2num ((uint8_t)15)

#define H3num ((uint8_t)16)
#define G3num ((uint8_t)17)
#define F3num ((uint8_t)18)
#define E3num ((uint8_t)19)
#define D3num ((uint8_t)20)
#define C3num ((uint8_t)21)
#define B3num ((uint8_t)22)
#define A3num ((uint8_t)23)

#define H4num ((uint8_t)24)
#define G4num ((uint8_t)25)
#define F4num ((uint8_t)26)
#define E4num ((uint8_t)27)
#define D4num ((uint8_t)28)
#define C4num ((uint8_t)29)
#define B4num ((uint8_t)30)
#define A4num ((uint8_t)31)

#define H5num ((uint8_t)32)
#define G5num ((uint8_t)33)
#define F5num ((uint8_t)34)
#define E5num ((uint8_t)35)
#define D5num ((uint8_t)36)
#define C5num ((uint8_t)37)
#define B5num ((uint8_t)38)
#define A5num ((uint8_t)39)

#define H6num ((uint8_t)40)
#define G6num ((uint8_t)41)
#define F6num ((uint8_t)42)
#define E6num ((uint8_t)43)
#define D6num ((uint8_t)44)
#define C6num ((uint8_t)45)
#define B6num ((uint8_t)46)
#define A6num ((uint8_t)47)

#define H7num ((uint8_t)48)
#define G7num ((uint8_t)49)
#define F7num ((uint8_t)50)
#define E7num ((uint8_t)51)
#define D7num ((uint8_t)52)
#define C7num ((uint8_t)53)
#define B7num ((uint8_t)54)
#define A7num ((uint8_t)55)

#define H8num ((uint8_t)56)
#define G8num ((uint8_t)57)
#define F8num ((uint8_t)58)
#define E8num ((uint8_t)59)
#define D8num ((uint8_t)60)
#define C8num ((uint8_t)61)
#define B8num ((uint8_t)62)
#define A8num ((uint8_t)63)

// struct that simply stores peice location data each bitboard has one for black and one for white
typedef struct RawBoard{

    uint64_t p; // pawns
    uint64_t n; // knights
    uint64_t b; // bishops
    uint64_t r; // rooks
    uint64_t q; // queen
    uint64_t k; // king

} RawBoard;

/* 
    INTERNAL BOARD REPRESENTATION
    the bitboard is meant to be fast and respect the spatial intuition of the chess board,
    it is to be thought of as a spatial analogue of the board from whites perspective
    the board will be stored with the higher ranks corresponding to higher powers of 2, 
    e.g. the 8th rank is stored in the 56-63 bits.
    the a-file can be thought of as the '7-file' and the h-file can be thought of as the '0-file'
    e.g. the a-file is stored in bits 7, 15, 23, 31, 39, 47, 55, and 63 (bits that are 7 mod 8)
    for example the white king is on the 8th rank and e-file ('4-file') in the starting position
    that corresponds to bit 59, so the black king bitboard in the starting position is:
    00001000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    and the bitboard for the white pawns in the starting position is
    00000000 00000000 00000000 00000000 00000000 00000000 11111111 00000000

*/
typedef struct BitBoard{

    // the locations of the peices
    RawBoard black;
    RawBoard white;

    // these next few may be amalgamated eventually

    uint8_t whiteToMove; // 0 if it is blacks turn and nonzero otherwise

    uint8_t castling;// bit 3 for white king, bit 2 for white queen, bit 1 for black king, bit 0 for black queen, (this matches FEN order) other bits unused for now

    uint16_t halfMoves; // 50 move rule clock, when it reaches 100 the player whose turn it is can claim a draw

    uint16_t moves; // move counter incremented after blacks mov

    // the positions of the two kings from 0-63
    uint8_t blackKingPos;
    uint8_t whiteKingPos;

    // two more bitboards that store all black pieces and all white pieces
    uint64_t blackPieces;
    uint64_t whitePieces;

    // even though 0 is a real squre we will use 0 to mean en passant is not possible since en passant on h1 is impossible 
    // non zero values here are assumed to be valid en passant squares
    uint64_t enPassant;


} BitBoard;

int isSquareAttacked(BitBoard *, uint8_t);

// there are a few basic and easy checks we can do to increase confidence the bitboard is good
// it should be noted that passing this check does NOT garuntee a valid board, only that it passed this sanity check
int validBitBoard(BitBoard);

// functions for debug printing
void printBits8(uint8_t);
void printBits16(uint16_t);
void printBits32(uint32_t);
void printBits64(uint64_t);
void printBitBoard64(uint64_t);
void debugPrintBitBoard(BitBoard);


#endif