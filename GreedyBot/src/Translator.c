#include <stdint.h>
#include "BitBoard.h"
#include "Translator.h"


BitBoard fenToBitBoard(const char* fen){

    BitBoard position = {(uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint64_t)0, (uint8_t)0, (uint8_t)0, (uint8_t)0, (uint16_t)0, (uint64_t)0};

    int count = 0, pos = 63;

    char curr;


    // first we loop over the board in the fen string and add peices accordingly
    do{

        curr = *(fen + count);

        switch(curr){
            case '1':
                pos -= 1;
                break;
            case '2':
                pos -= 2;
                break;
            case '3':
                pos -= 3;
                break;
            case '4':
                pos -= 4;
                break;
            case '5':
                pos -= 5;
                break;
            case '6':
                pos -= 6;
                break;
            case '7':
                pos -= 7;
                break;
            case '8':
                pos -= 8;
                break;
            case 'K':
                position.white.k = position.white.k | (1ull << pos);
                pos -= 1;
                break;
            case 'Q':
                position.white.q = position.white.q | (1ull << pos);
                pos -= 1;
                break;
            case 'R':
                position.white.r = position.white.r | (1ull << pos);
                pos -= 1;
                break;
            case 'B':
                position.white.b = position.white.b | (1ull << pos);
                pos -= 1;
                break;
            case 'N':
                position.white.n = position.white.n | (1ull << pos);
                pos -= 1;
                break;
            case 'P':
                position.white.p = position.white.p | (1ull << pos);
                pos -= 1;
                break;
            case 'k':
                position.black.k = position.black.k | (1ull << pos);
                pos -= 1;
                break;
            case 'q':
                position.black.q = position.black.q | (1ull << pos);
                pos -= 1;
                break;
            case 'r':
                position.black.r = position.black.r | (1ull << pos);
                pos -= 1;
                break;
            case 'b':
                position.black.b = position.black.b | (1ull << pos);
                pos -= 1;
                break;
            case 'n':
                position.black.n = position.black.n | (1ull << pos);
                pos -= 1;
                break;
            case 'p':
                position.black.p = position.black.p | (1ull << pos);
                pos -= 1;
                break;
            case '/':
                break;
            case ' ': 
                // the last iteration of the while loop goes here
                break;
            default: 
                // if we get here there is a problem so error handling goes here later
                break;
        }

        count++;

    } while(curr != ' ');


    // after consuming the first space we have arrived at the character that is either 'b' or 'w' for which player is to move
    curr = *(fen + count);
    position.whiteToMove = (curr == 'w') ? (uint8_t)1 : (uint8_t)0;
    count += 2; // consume the turn char and the next space

    // now we look for castling rights
    do{
        curr = *(fen + count);

        switch(curr){
            case 'K':
                position.castling = position.castling | (uint8_t)8;
                break;
            case 'Q':
                position.castling = position.castling | (uint8_t)4;
                break;
            case 'k':
                position.castling = position.castling | (uint8_t)2;
                break;
            case 'q':
                position.castling = position.castling | (uint8_t)1;
                break;
            case '-':
                break;
            case ' ': 
                // last iteration of the loop
                break;
            default: 
                // error handling goes here later
                break;
        }

        count ++;

    }while(curr != ' ');

    // now check if there is an en passant square
    curr = *(fen + count);

    if(curr == '-'){ 
        count += 2;
        // there is no en passant so do nothing because enPassant is initialized to 0
    }
    else{
        int square = (7 - (curr - 'a')) + ((*(fen + count + 1) - '0') - 1) * 8;
        position.enPassant = 1ull << square;
        count += 3; // need to skip the two chars that denote the square and the next space
    }

    // now read the half move count
    // gonna make a simple atoi to avoid including the whole stdlib for 2 function calls
    uint8_t buf[10];
    int bufPos = 0;
    while(1){
        
        curr = *(fen + count);
        count++;

        if(curr == ' '){ // found the end of the number
            break;
        }
        else{
            buf[bufPos] = curr;
        }

        bufPos++;
    }

    uint8_t factor = 1;
    for(int i = bufPos - 1; i >= 0; i--){
        position.halfMoves += (buf[i] - '0') * factor;
        factor = factor * 10;
    }


    // finally we read the whole moves count
    bufPos = 0;
    while(1){

        curr = *(fen + count);
        count++;

        if(curr == 0){ // found the end of the number
            break;
        }
        else{
            buf[bufPos] = curr;
        }

        bufPos++;
    }

    uint16_t factor1 = 1;
    for(int i = bufPos - 1; i >= 0; i--){
        position.moves += (buf[i] - '0') * factor1;
        factor1 = factor1 * 10;
    }

    return position;

}







// fen should be pre allocated, probably 90 chars is enough but I'll use 100 to be safe
void bitBoardToFen(BitBoard board, char* fen){

    int count = 0;
    uint8_t empty = 0;

    // gonna loop over each bit of each peice board to write the position
    for(int i = 63; i >= 0; i--){

        // every 8 squares we put a '/'
        if(i % 8 == 7 && i < 63){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }            
            *(fen + count) = '/';
            count ++;
        }

        // the mask for the square we care about this iteration
        uint64_t mask = 1ull << i;
        // now start seeing if/which peice is on this square
        if(board.white.k & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'K';
            count++;
        }
        else if(board.white.q & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'Q';
            count++;
        }
        else if(board.white.r & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'R';
            count++;
        }
        else if(board.white.b & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'B';
            count++;
        }
        else if(board.white.n & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'N';
            count++;
        }
        else if(board.white.p & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'P';
            count++;
        }
        else if(board.black.k & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'k';
            count++;
        }
        else if(board.black.q & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'q';
            count++;
        }
        else if(board.black.r & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'r';
            count++;
        }
        else if(board.black.b & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'b';
            count++;
        }
        else if(board.black.n & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'n';
            count++;
        }
        else if(board.black.p & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'p';
            count++;
        }
        else{
            empty++;
        }

    }
    if(empty > 0){ // this handle the edge case of when there are emoty squares trailing
        *(fen + count) = '0' + empty;
        empty = 0;
        count++;
    }

    // add the first space
    *(fen + count) = ' ';
    count++;

    // now add whose turn it is to move
    if(board.whiteToMove){
        *(fen + count) = 'w';
    }
    else{
        *(fen + count) = 'b';
    }
    count++;
    // add the second space
    *(fen + count) = ' ';
    count++;

    // now add castling info
    uint8_t castle = board.castling;
    if(castle & (uint8_t)8){ // white can castle kingside
        *(fen + count) = 'K';
        count++;
    }
    if(castle & (uint8_t)4){ // white can castle queenside
        *(fen + count) = 'Q';
        count++;
    }
    if(castle & (uint8_t)2){ // black can castle kingside
        *(fen + count) = 'k';
        count++;
    }
    if(castle & (uint8_t)1){ // black can castle queenside
        *(fen + count) = 'q';
        count++;
    }
    if(!castle){ // neither side can castle at all
        *(fen + count) = '-';
        count++;
    }

    // add the third space
    *(fen + count) = ' ';
    count++;

    // now add en passant info
    if(board.enPassant){

        uint64_t passant = board.enPassant;
        char file = 'h', rank = '1';

        while(passant > 255){ // find the rank
            passant = passant >> 8;
            rank++;
        }

        while(passant > 1){
            passant = passant >> 1;
            file--;
        }

        *(fen + count) = file;
        *(fen + count + 1) = rank;
        count += 2;

    }
    else{ 
        *(fen + count) = '-';
        count ++;
    }

    // add the fourth space
    *(fen + count) = ' ';
    count++;

    // now add the halfmove count
    uint8_t half = board.halfMoves, LSD;
    int digits = 0;
    uint8_t buf[10];
    do{
        LSD = half % 10;
        buf[digits] = '0' + LSD;
        digits++;
        half = (half - LSD)/10;
    }while(half > 0);

    for(int i = 0; i < digits; i++){
        *(fen + count) = buf[digits - 1 - i];
        count++;
    }


    // add the fifth space
    *(fen + count) = ' ';
    count++;

    // now add the move count
    uint16_t moves = board.moves, lsd;
    digits = 0;
    do{
        lsd = moves % 10;
        buf[digits] = '0' + (uint8_t)lsd;
        digits++;
        moves = (moves - (int)lsd)/10;
    }while(moves > 0);

    for(int i = 0; i < digits; i++){
        *(fen + count) = buf[digits - 1 - i];
        count++;
    }

    // finally we can add the string terminating character
    *(fen + count) = '\0';

}


void moveToUCI(uint32_t move, char *UCImove){

    uint32_t from = startMask & move;
    uint32_t to = (endMask & move) >> 6;

    uint32_t fromFile = 7 - (from % 8);
    uint32_t fromRank = from / 8;

    uint32_t toFile = 7 - (to % 8);
    uint32_t toRank = to / 8;

    *(UCImove) = 'a' + fromFile;
    *(UCImove + 1) = '1' + fromRank;
    *(UCImove + 2) = 'a' + toFile;
    *(UCImove + 3) = '1' + toRank;

    if(isPromoMask & move){
        switch((move & promoPieceMask) >> 12){
            case 0:
                *(UCImove + 4) = 'n';
                break;
            case 1:
                *(UCImove + 4) = 'b';
                break;
            case 2:
                *(UCImove + 4) = 'r';
                break;
            case 3:
                *(UCImove + 4) = 'q';
                break;
        }
        *(UCImove + 5) = '\0';
    }
    else{
        *(UCImove + 4) = '\0';
    }


}
