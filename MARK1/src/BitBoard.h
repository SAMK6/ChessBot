#ifndef BITBOARD_H
#define BITBOARD_H

// the bitboard uses "little endian" conventions so the 0-bit is the rightmost or least significant bit


// define all the "squares"
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

    the usual initialization of the bitboard will be all 0 values as follows
    BitBoard board = {(Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned short)0, (Bint)0};

*/
typedef struct BitBoard{

    unsigned long K; // white king
    unsigned long Q; // white queen
    unsigned long R; // white rooks
    unsigned long B; // white bishops
    unsigned long N; // white knights
    unsigned long P; // white pawns

    unsigned long k; // black king
    unsigned long q; // black queen
    unsigned long r; // black rooks
    unsigned long b; // black bishops
    unsigned long n; // black knights
    unsigned long p; // black pawns

    // these next few may be amalgamated eventually

    unsigned char whiteToMove; // 0 if it is blacks turn and nonzero otherwise

    // bit 3 for white king, bit 2 for white queen, bit 1 for black king, bit 0 for black king, other bits unused for now
    unsigned char castling;
    unsigned char halfMoves; // 50 move rule clock, when it reaches 100 the game is a draw

    unsigned short moves; // move counter


    // even though 0 is a real squre we will use 0 to mean en passant is not possible since en passant on h1 is impossible 
    // non zero values here are assumed to be valid en passant squares
    unsigned long enPassant;


} BitBoard;


// there are a few basic and easy checks we can do to increase confidence the bitboard is good
// it should be noted that passing this check does NOT garuntee a valid board, only that it passed this sanity check
int validBitBoard(BitBoard);

// two functions for debug printing
void printBits(void*, int);
void debugPrintBitBoard(BitBoard);




typedef unsigned long Bint; // Bint == board int, will be used frequently for setting bits




#endif