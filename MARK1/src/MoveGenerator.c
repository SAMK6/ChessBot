#include <stdint.h>
#include <stdio.h>
#include "BitBoard.h"
#include "MoveGenerator.h"

uint64_t generateRookMask(uint8_t square, RawBoard friendly, RawBoard enemy){

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

uint64_t generateBishopMask(uint8_t square, RawBoard friendly, RawBoard enemy){

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

uint64_t generateKnightMask(uint8_t square, uint64_t friendlyPieces){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    printf("\n\n%d:%d\n\n", rank, file);


    // each of these staementas makes sure the knight is far enough away from the edge of the board for any of its 8 possible moves
    if(rank < (uint8_t)7 && file < (uint8_t)6) mask = mask | (pos << (uint8_t)10);

    if(rank < (uint8_t)6 && file < (uint8_t)7) mask = mask | (pos << (uint8_t)17);

    if(rank < (uint8_t)6 && file > (uint8_t)0) mask = mask | (pos << (uint8_t)15);

    if(rank < (uint8_t)7 && file > (uint8_t)1) mask = mask | (pos << (uint8_t)6);

    if(rank > (uint8_t)0 && file > (uint8_t)1) mask = mask | (pos >> (uint8_t)10);

    if(rank > (uint8_t)1 && file > (uint8_t)0) mask = mask | (pos >> (uint8_t)17);

    if(rank > (uint8_t)1 && file < (uint8_t)7) mask = mask | (pos >> (uint8_t)15);

    if(rank > (uint8_t)0 && file < (uint8_t)6) mask = mask | (pos >> (uint8_t)6);

    // make sure a friendly peices doesnt occupy the square
    mask = mask & ~friendlyPieces;

    return mask;

}

uint64_t generateQueenMask(uint8_t square, RawBoard friendly, RawBoard enemy){

    return generateRookMask(square, friendly, enemy) | generateBishopMask(square, friendly, enemy);

}

uint64_t generateKingMask(uint8_t square, RawBoard friendly, RawBoard enemy){

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
