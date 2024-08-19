#include <stdint.h>
#include <stdio.h>
#include "BitBoard.h"
#include "MoveGenerator.h"

uint64_t generateRookMask(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // first add the squares on the same rank
    for(uint8_t i = 0; i < (uint8_t)8; i++){
        if(i != rank){
            mask = mask | ((uint64_t)1 << ((uint8_t)8 * i + file));
        }
    }  
    
    //now add the squares on the same file
    for(uint8_t j = 0; j < (uint8_t)8; j++){
        if(j != file){
            mask = mask | (uint64_t)1 << ((uint8_t)8 * rank + j);
        }
    }

    return mask;

}

uint64_t generateBishopMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;
    
    uint8_t left = (uint8_t)7 - file;
    uint8_t right = file;
    uint8_t up = (uint8_t)7 - rank;
    uint8_t down = rank;

    // first add squares to the top left of the bishop
    uint8_t offset = (uint8_t)1;
    while(offset <= up && offset <= left){

        mask = mask | (pos << (offset * (uint8_t)9));
        offset ++;

    }

    // next add squares to the top right of the bishop
    offset = (uint8_t)1;
    while(offset <= up && offset <= right){

        mask = mask | (pos << (offset * (uint8_t)7));
        offset ++;

    }

    // next add squares to the bottom left of the bishop
    offset = (uint8_t)1;
    while(offset <= down && offset <= left){

        mask = mask | (pos >> (offset * (uint8_t)7));
        offset ++;

    }

    // finally add squares to the bottom right of the bishop
    offset = (uint8_t)1;
    while(offset <= down && offset <= right){

        mask = mask | (pos >> (offset * (uint8_t)9));
        offset ++;

    }

    return mask;

}

uint64_t generateKnightMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    printf("\n\n%d:%d\n\n", rank, file);

    if(rank < (uint8_t)7 && file < (uint8_t)6) mask = mask | (pos << (uint8_t)10);

    if(rank < (uint8_t)6 && file < (uint8_t)7) mask = mask | (pos << (uint8_t)17);

    if(rank < (uint8_t)6 && file > (uint8_t)0) mask = mask | (pos << (uint8_t)15);

    if(rank < (uint8_t)7 && file > (uint8_t)1) mask = mask | (pos << (uint8_t)6);

    if(rank > (uint8_t)0 && file > (uint8_t)1) mask = mask | (pos >> (uint8_t)10);

    if(rank > (uint8_t)1 && file > (uint8_t)0) mask = mask | (pos >> (uint8_t)17);

    if(rank > (uint8_t)1 && file < (uint8_t)7) mask = mask | (pos >> (uint8_t)15);

    if(rank > (uint8_t)0 && file < (uint8_t)6) mask = mask | (pos >> (uint8_t)6);

    return mask;

}

uint64_t generateQueenMask(uint8_t square){

    return generateRookMask(square) | generateBishopMask(square);

}

uint64_t generateKingMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    if(rank != (uint8_t)7){ // check if the king it at the top of the board

        mask = mask | (pos << 8);

        if(file != (uint8_t)7){
            mask = mask | (pos << 9);
            mask = mask | (pos << 1);
        }
        if(file != (uint8_t)0){
            mask = mask | (pos << 7);
            mask = mask | (pos >> 1);
        }

    }

    if(rank != (uint8_t)0){ // check if the king is at the bottom of the board

        mask = mask | (pos >> 8);

        if(file != (uint8_t)7){
            mask = mask | (pos >> 7);
            mask = mask | (pos << 1);
        }
        if(file != (uint8_t)0){
            mask = mask | (pos >> 9);
            mask = mask | (pos >> 1);
        }

    }

    return mask;

}



void generateMovesWhite(BitBoard board, Move* moves){

    // a board that simply has the position of all oponnent pieces
    uint64_t opBoard = board.black.k | board.black.q | board.black.r | board.black.b | board.black.n | board.black.p;
    uint64_t myBoard = board.white.k | board.white.q | board.white.r | board.white.b | board.white.n | board.white.p;
    uint64_t wholeBoard = opBoard | myBoard;

    RawBoard friendlyPieces = board.white;

    int pos = 0; // where in the movelist to put moves

    // first we generate pawn moves
    uint64_t pawnMask = H2; // white pawns cant be on the first rank
    for(int i = 0; i < 55; i ++){

        if(pawnMask & friendlyPieces.p){ // we found a pawn check which moves it can make

            

        }

        pawnMask << 1;

    }


}

void generateMovesBlack(BitBoard board, Move* moves){




    
}

void generateMoves(BitBoard board, Move* moves){

    if(board.whiteToMove){
        generateMovesWhite(board, moves);
    }
    else{
        generateMovesBlack(board, moves);
    }


}
