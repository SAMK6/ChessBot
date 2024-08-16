#include "BitBoard.h"
#include "MoveGenerator.h"


void generateMoves(BitBoard board, Move* moves){

    if(board.whiteToMove){
        generateMovesWhite(board, moves);
    }
    else{
        generateMovesBlack(board, moves);
    }


}

void generateMovesWhite(BitBoard board, Move* moves){

    // a board that simply has the position of all oponnent pieces
    Bint opBoard = board.black.k | board.black.q | board.black.r | board.black.b | board.black.n | board.black.p;
    Bint myBoard = board.white.k | board.white.q | board.white.r | board.white.b | board.white.n | board.white.p;
    Bint wholeBoard = opBoard | myBoard;

    RawBoard friendlyPieces = board.white;

    int pos = 0; // where in the movelist to put moves

    // first we generate pawn moves
    Bint pawnMask = H2; // white pawns cant be on the first rank
    for(int i = 0; i < 55; i ++){

        if(pawnMask & friendlyPieces.p){ // we found a pawn check which moves it can make

            

        }

        pawnMask << 1;

    }


}

void generateMovesBlack(BitBoard board, Move* moves){




    
}