#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include <stdint.h>
#include "BitBoard.h"


/*
    Moves will be from-to notation with 24 bits of extra info to be filled out as deemed needed
    bits 0-5 are the start square, we can use these to bit shift and create the piece mask later
    bits 6-11 are the end square, 
    bits 12-15 are as follows (misc codes):
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
    bits 16-19 are used for which piece is moving
        0 for black pawn
        1 for black knight
        2 for black bishop
        3 for black rook
        4 for black queen
        5 for black king
        6 for white pawn
        7 for white knight
        8 for white bishop
        9 for white rook
        10 for white queen
        11 for white king


    the nullmove is all zeros

    I originally had this idea but didnt realise that bits 14-15 could still be used if the move is not a promotion,
    after reading CPW (https://www.chessprogramming.org/Encoding_Moves) I realised bits 14-15 could be used either way and 
    therefore my move representation is a extended version the encoding used in the article
*/


#define buildMove(from, to, code, piece) ((Move)from | ((Move)to << 6) | ((Move)code << 12) | ((Move)piece << 16))

// define masks used to move the rooks during castling moves
// NOT USED AS MASKS TO CHECK CASTLING RIGHTS
#define whiteKingsideCastle 5ull
#define whiteQueensideCastle 144ull
#define blackKingsideCastle 360287970189639680ull
#define blackQueensideCastle 10376293541461622784ull

BitBoard makeMove(BitBoard, Move); // makes a move and returns the new bitboard
int isSquareAttacked(BitBoard*, uint8_t);
int generateMovesBlack(BitBoard*, Move*);
int generateMovesWhite(BitBoard*, Move*);

#endif