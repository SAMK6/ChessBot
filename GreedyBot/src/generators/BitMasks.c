#include <stdint.h>
#include "BitMasks.h"


// the functions in this file are replaced by the arrays in Magics.h but the functions stay for testing and just in case

uint64_t generateRookMask(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // first add the squares on the same rank
    for(uint8_t i = 1; i < (uint8_t)7; i++){
        if(i != rank){
            mask |= ((uint64_t)1 << ((uint8_t)8 * i + file));
        }
    }  
    
    //now add the squares on the same file
    for(uint8_t j = 1; j < (uint8_t)7; j++){
        if(j != file){
            mask |= (uint64_t)1 << ((uint8_t)8 * rank + j);
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
    while(offset < up && offset < left){

        mask |= (pos << (offset * (uint8_t)9));
        offset ++;

    }

    // next add squares to the top right of the bishop
    offset = (uint8_t)1;
    while(offset < up && offset < right){

        mask |= (pos << (offset * (uint8_t)7));
        offset ++;

    }

    // next add squares to the bottom left of the bishop
    offset = (uint8_t)1;
    while(offset < down && offset < left){

        mask |= (pos >> (offset * (uint8_t)7));
        offset ++;

    }

    // finally add squares to the bottom right of the bishop
    offset = (uint8_t)1;
    while(offset < down && offset < right){

        mask |= (pos >> (offset * (uint8_t)9));
        offset ++;

    }

    return mask;

}


uint64_t generateKnightMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // each of these staementas makes sure the knight is far enough away from the edge of the board for any of its 8 possible moves
    if(rank < (uint8_t)7 && file < (uint8_t)6) mask |= (pos << 10);

    if(rank < (uint8_t)6 && file < (uint8_t)7) mask |= (pos << 17);

    if(rank < (uint8_t)6 && file > (uint8_t)0) mask |= (pos << 15);

    if(rank < (uint8_t)7 && file > (uint8_t)1) mask |= (pos << 6);

    if(rank > (uint8_t)0 && file > (uint8_t)1) mask |= (pos >> 10);

    if(rank > (uint8_t)1 && file > (uint8_t)0) mask |= (pos >> 17);

    if(rank > (uint8_t)1 && file < (uint8_t)7) mask |= (pos >> 15);

    if(rank > (uint8_t)0 && file < (uint8_t)6) mask |= (pos >> 6);

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

        mask |= (pos << 8);

        if(file != (uint8_t)7){
            mask |= (pos << 9);
            mask |= (pos << 1);
        }
        if(file != (uint8_t)0){
            mask |= (pos << 7);
            mask |= (pos >> 1);
        }

    }

    if(rank != (uint8_t)0){ // check if the king is at the bottom of the board

        mask |= (pos >> 8);

        if(file != (uint8_t)7){
            mask |= (pos >> 7);
            mask |= (pos << 1);
        }
        if(file != (uint8_t)0){
            mask |= (pos >> 9);
            mask |= (pos >> 1);
        }

    }

    return mask;

}

uint64_t generatePawnMaskBlack(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t file = square % (uint8_t)8;

    if(file < 7) mask |= (1ull << square) >> 7;

    if(file > 0) mask |= (1ull << square) >> 9;

    return mask;

}

uint64_t generatePawnMaskWhite(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t file = square % (uint8_t)8;

    if(file < 7) mask |= (1ull << square) << 9;

    if(file > 0) mask |= (1ull << square) << 7;

    return mask;

}

uint64_t generateBishopAttacks(uint8_t square, uint64_t pieces){

    uint64_t blockers = pieces;
    
    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    int rank = (int)(square / (uint8_t)8);
    int file = (int)(square % (uint8_t)8);

    // add the attacked squares to the top left
    int offset = 1;
    while(rank + offset < 8 && file + offset < 8){

        mask |= pos << (9 * offset);

        if((pos << (9 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the top right
    offset = 1;
    while(rank + offset < 8 && file - offset >= 0){

        mask |= pos << (7 * offset);

        if((pos << (7 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the bottom right
    offset = 1;
    while(rank - offset >= 0 && file - offset >= 0){

        mask |= pos >> (9 * offset);

        if((pos >> (9 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the bottom left
    offset = 1;
    while(rank - offset >= 0 && file + offset < 8){

        mask |= pos >> (7 * offset);

        if((pos >> (7 * offset)) & blockers) break;

        offset++;

    }
    
    return mask;
    
}

uint64_t generateRookAttacks(uint8_t square, uint64_t pieces){

    uint64_t blockers = pieces;

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;


    // squares the rook attacks above the rook
    for(int i = (int)rank + 1; i < 8; i++){

        mask |= (pos << (8 * (i - rank)));

        if((pos << (8 * (i - rank))) & blockers) break;

    }
    
    // squares below the rook
    for(int i = (int)rank - 1; i >= 0; i--){

        mask |= (pos >> (8 * (rank - i)));

        if((pos >> (8 * (rank - i))) & blockers) break;

    }

    // squares to thr right of the rook
    for(int i = (int)file - 1; i >= 0; i--){

        mask |= (pos >> (file - i));
        if((pos >> (file - i)) & blockers) break;

    }

    // squares to thr left of the rook
    for(int i = (int)file + 1; i < 8; i++){

        mask |= (pos << (i - file));
        if((pos << (i - file)) & blockers) break;

    }

    return mask;

}



uint64_t generateLineMask(uint8_t square1, uint8_t square2){


    int8_t rank1 = square1 / 8;
    int8_t rank2 = square2 / 8;
    int8_t file1 = square1 % 8;
    int8_t file2 = square2 % 8;

    uint64_t mask = 0ull;

    if(rank1 == rank2){ // horizontal line
        if(file2 > file1){
            uint8_t temp = file1;
            file1 = file2;
            file2 = temp;
        }

        for(int8_t i = file2; i <= file1; i++){
            mask |= (1ull << (8 * rank1 + i));
        }

    }
    else if(file1 == file2){ // vertical line
        if(rank2 > rank1){
            int8_t temp = rank1;
            rank1 = rank2;
            rank2 = temp;
        }

        for(int8_t i = rank2; i <= rank1; i++){
            mask |= (1ull << (8 * i + file1));
        }
        
    }
    else if(((file1 - file2) == (rank1 - rank2))){ // northwest to southeast diagonal

        uint8_t start, distance;
        if(rank1 > rank2){ // file1 is the top left corner
            start = square2;
            distance = rank1 - rank2;
        }
        else{
            start = square1;
            distance = rank2 - rank1;
        }

        for(uint8_t i = 0; i <= distance; i++){

            mask |= start << (i * 9);

        }

    }
    else if(((file1 - file2) == (rank2 - rank1))){ // northeast to southwest diagonal

        uint8_t start, distance;
        if(rank1 > rank2){ // file1 is the top left corner
            start = square2;
            distance = rank1 - rank2;
        }
        else{
            start = square1;
            distance = rank2 - rank1;
        }

        for(uint8_t i = 0; i <= distance; i++){

            mask |= start << (i * 7);

        }

    }
    else{ // not on a line
        mask |= ((1ull << square1) | (1ull << square2));
    }

    return mask;

}