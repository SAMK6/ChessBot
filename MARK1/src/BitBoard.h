#ifndef BITBOARD_H
#define BITBOARD_H

// the bitboard uses "little endian" conventions so the 0-bit is the rightmost or least significant bit

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




/*
    Moves will be from-to notation with 4 bits for extra info
    bits 0-5 are the from square, we can use these to bit shift and create the piece mask later
    bits 6-11 are the to square, 
    bit 12 represents whether or not the move is a capture
    bit 13 represents whethere the move is a promotion or not
    if bit 13 then bits 14-15 represent the piece the pawn is promoted to, 00 for knight, 01 for bishop, 10 for rook, 11 for queen
    if ~bit 13 then bits 14-15 represent misc info, 00 for 

    I originally had this idea but neglected to realise that bits 14-15 could still be used if the move is not a promotion,
    after reading CPW (https://www.chessprogramming.org/Encoding_Moves) I realised bits 14-15 could be used either way and 
    therefore my move representation is a simplified version of the table used in the article linked 
*/
typedef unsigned short Move;



#endif