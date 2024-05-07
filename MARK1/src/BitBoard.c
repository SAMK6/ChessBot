#include "BitBoard.h"


int validBitBoard(BitBoard board){

    // first check is since there cannot be two peices on one squre the bitwise and of all the piece boards should be 0
    Bint check = board.K & board.Q & board.R & board.B & board.N & board.P & board.k & board.q & board.r & board.b & board.n & board.p;
    if(check){
        return 0;
    }

    // next we can check that if there is an en passant square there must be a pawn in front of it
    // and depending on which peice can be captured en passant we check it is the correct players turn
    if(board.enPassant){

        Bint pawn;
        if(board.enPassant > (Bint)2147483648){ // black pawn can be captured en passant
            pawn = board.enPassant >> 8;

            if(!((pawn & board.p) == pawn) || !board.whiteToMove){
                return 0;
            }
        }
        else{ // white pawn can be captured en passant
            pawn = board.enPassant << 8;

            if(!((pawn & board.P) == pawn) || board.whiteToMove){
                return 0;
            }
        }
    }

    // finally we can check that if castling is allowed the rooks and kings are in the proper position



    return 1;

}