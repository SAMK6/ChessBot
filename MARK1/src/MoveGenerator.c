#include <stdint.h>
#include <stdio.h>
#include "BitBoard.h"
#include "MoveGenerator.h"



/*

    the general movegen strat will be to obtain a mask for the given piece,
    check if that piece is pinned to the king, obtain a movement mask for the peice, 
    depening on if it is pinned to the king and which squares are taken by friendly pieces we determine the possible moves

*/

void generateMovesWhite(BitBoard *board, Move *moves){

    // a board that simply has the position of all oponnent pieces
    uint64_t opBoard = board->black.k | board->black.q | board->black.r | board->black.b | board->black.n | board->black.p;
    // a board that contains all friendly pieces
    uint64_t myBoard = board->white.k | board->white.q | board->white.r | board->white.b | board->white.n | board->white.p;
    // a board that contains all pieces
    uint64_t wholeBoard = opBoard | myBoard;


    RawBoard friendlyPieces = board->white;
    RawBoard enemyPieces = board->black;

    int pos = 0; // where in the movelist to put moves



}

void generateMovesBlack(BitBoard *board, Move *moves){




    
}

void generateMoves(BitBoard *board, Move *moves){

    if(board->whiteToMove){
        generateMovesWhite(board, moves);
    }
    else{
        generateMovesBlack(board, moves);
    }


}
