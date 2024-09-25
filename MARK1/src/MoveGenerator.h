#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include <stdint.h>
#include "BitBoard.h"


/*
    Moves will be from-to notation with 4 bits for extra info
    bits 0-5 are the start square, we can use these to bit shift and create the piece mask later
    bits 6-11 are the end square, 
    the remaining 4 bits are as follows (misc codes):
        0 for quiet moves
        1 for double pawn push
        2 for kingside castle
        3 for queenside castle
        4 for captures
        5 for en passant captures
        8 for knight promo
        9 for bishop promo
        10 for rook promo
        11 for queen promo
        12 for knight promo-capture
        13 for bishop promo-capture
        14 for rook promo-capture
        15 for queen promo-capture

    need a use for 6 and 7 (maybe checks)

    the nullmove is all zeros

    I originally had this idea but didnt realise that bits 14-15 could still be used if the move is not a promotion,
    after reading CPW (https://www.chessprogramming.org/Encoding_Moves) I realised bits 14-15 could be used either way and 
    therefore my move representation is a modified version of the table used in the article linked
*/
typedef uint16_t Move;
typedef struct MoveBoard{ // this struct holds a bitboard and the move that created it
    
    Move move;
    BitBoard board;

} MoveBoard;

#define buildMove(from, to, code) (Move)((uint16_t)from | ((uint16_t)to << 6) | ((uint16_t)code << 12))

// gonna define masks to get specific parts of the move object
#define startMask (Move)63 // first 6 bits (0-5)
#define endMask (Move)4032 // second 6 bits (6-11)
#define isCaptureMask (Move)16384 // 14th bit
#define isPromoMask (Move)32768 // 15th bit
#define pieceMask (Move)12288 // bits 12 and 13
#define miscMask (Move)61440 // bits 12-15

// define masks used to move the rooks during castling moves
// NOT USED AS MASKS TO CHECK CASTLING RIGHTS
#define whiteKingsideCastle 5ull
#define whiteQueensideCastle 144ull
#define blackKingsideCastle 360287970189639680ull
#define blackQueensideCastle 10376293541461622784ull

BitBoard makeMove(BitBoard, Move, char); // makes a move and returns the new bitboard
int isSquareAttacked(BitBoard*, uint8_t);
int generateMovesBlack(BitBoard*, MoveBoard*);
int generateMovesWhite(BitBoard*, MoveBoard*);

#endif