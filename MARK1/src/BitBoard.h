#ifndef BITBOARD_H
#define BITBOARD_H

// internal board representation
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

} BitBoard;

#endif