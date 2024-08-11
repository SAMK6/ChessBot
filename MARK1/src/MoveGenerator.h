#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "BitBoard.h"

// function that takes in a bitboard and returns the possible moves in the position
// generateMoves(BitBoard);


/*
    Moves will be from-to notation with 4 bits for extra info
    bits 0-5 are the start square, we can use these to bit shift and create the piece mask later
    bits 6-11 are the end square, 
    bit 12 represents whether or not the move is a capture
    bit 13 represents whethere the move is a promotion or not
    if bit 13 is set then bits 14-15 represent the piece the pawn is promoted to, 00 for knight, 01 for bishop, 10 for rook, 11 for queen
    if bit 13 is unset then bits 14-15 represent misc info, 00 for 

    the nullmove is all zeros

    I originally had this idea but didnt realise that bits 14-15 could still be used if the move is not a promotion,
    after reading CPW (https://www.chessprogramming.org/Encoding_Moves) I realised bits 14-15 could be used either way and 
    therefore my move representation is a simplified version of the table used in the article linked (maybe with bits reversed I cant tell)
*/
typedef unsigned short Move;


// lazily generate king moves
Move genKingMoves(unsigned char);

// lazily generate queen moves
Move genQueenMoves(unsigned char);

// lazily generate rook moves
Move genRookMoves(unsigned char);

// lazily generate bishop moves
Move genBishopMoves(unsigned char);

// lazily generate knight moves
Move genKnightMoves(unsigned char);

// lazily generate pawn moves
Move genPawnMoves(unsigned char);



// check a king move for validity
Move checkKingMove(BitBoard, Move);

// check a queen move for validity
Move checkQueenMove(BitBoard, Move);

// check a rook move for validity
Move checkRookMove(BitBoard, Move);

// check a bishop move for validity
Move checkBishopMove(BitBoard, Move);

// check a knight move for validity
Move checkKnightMove(BitBoard, Move);

// check a pawn move for validity
Move checkPawnMove(BitBoard, Move);

#endif