#include "BitBoard.h"
#include "Translator.h"
#include <stdio.h>


BitBoard fenToBitBoard(const char* fen){

    BitBoard position = {(Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned short)0, (Bint)0};

    int count = 0, pos = 63;

    unsigned char curr;

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
                position.K = position.K | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'Q':
                position.Q = position.Q | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'R':
                position.R = position.R | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'B':
                position.B = position.B | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'N':
                position.N = position.N | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'P':
                position.P = position.P | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'k':
                position.k = position.k | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'q':
                position.q = position.q | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'r':
                position.r = position.r | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'b':
                position.b = position.b | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'n':
                position.n = position.n | ((Bint)1 << pos);
                pos -= 1;
                break;
            case 'p':
                position.p = position.p | ((Bint)1 << pos);
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
    position.whiteToMove = (curr == 'w') ? (unsigned char)1 : (unsigned char)0;
    count += 2; // consume the turn char and the next space

    // now we look for castling rights
    do{
        curr = *(fen + count);

        switch(curr){
            case 'K':
                position.castling = position.castling | (unsigned char)8;
                break;
            case 'Q':
                position.castling = position.castling | (unsigned char)4;
                break;
            case 'k':
                position.castling = position.castling | (unsigned char)2;
                break;
            case 'q':
                position.castling = position.castling | (unsigned char)1;
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
        position.enPassant = (Bint)1 << square;
        count += 3; // need to skip the two chars that denote the square and the next space
    }

    // now read the half move count
    // gonna make a simple atoi to avoid including the whole stdlib for 2 function calls
    unsigned char buf[10];
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

    unsigned char factor = 1;
    for(int i = bufPos - 1; i >= 0; i--){
        position.halfMoves += (buf[i] - '0') * factor;
        factor = factor * 10;
    }


    // finally we read the whole moves count
    bufPos = 0;
    while(1){

        printf("lolol");

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

    unsigned short factor1 = 1;
    for(int i = bufPos - 1; i >= 0; i--){
        position.moves += (buf[i] - '0') * factor1;
        factor1 = factor1 * 10;
    }

    return position;

}

// fen should be pre allocated, probably 90 chars is enough but I'll use 100 to be safe and avoid weirdness
void bitBoardToFen(BitBoard board, char* fen){

    int count = 0;
    unsigned char empty = 0;

    // gonna loop over each bit of each peice board to write the position
    for(int i = 63; i >= 0; i--){

        // every 8 squares we put a '/'
        if(i % 8 == 7 && i < 63){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }            *(fen + count) = '/';
            count ++;
        }

        // the mask for the square we care about this iteration
        Bint mask = (Bint)1 << i;
        // now start seeing if/which peice is on this square
        if(board.K & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'K';
            count++;
        }
        else if(board.Q & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'Q';
            count++;
        }
        else if(board.R & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'R';
            count++;
        }
        else if(board.B & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }

            *(fen + count) = 'B';
            count++;
        }
        else if(board.N & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'N';
            count++;
        }
        else if(board.P & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'P';
            count++;
        }
        else if(board.k & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'k';
            count++;
        }
        else if(board.q & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'q';
            count++;
        }
        else if(board.r & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'r';
            count++;
        }
        else if(board.b & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'b';
            count++;
        }
        else if(board.n & mask){
            if(empty > 0){
                *(fen + count) = '0' + empty;
                empty = 0;
                count++;
            }
            
            *(fen + count) = 'n';
            count++;
        }
        else if(board.p & mask){
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
    unsigned char castle = board.castling;
    if(castle & (unsigned char)8){ // white can castle kingside
        *(fen + count) = 'K';
        count++;
    }
    if(castle & (unsigned char)4){ // white can castle queenside
        *(fen + count) = 'Q';
        count++;
    }
    if(castle & (unsigned char)2){ // black can castle kingside
        *(fen + count) = 'k';
        count++;
    }
    if(castle & (unsigned char)1){ // black can castle queenside
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

        Bint passant = board.enPassant;
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


    // finally we can add the string terminating character
    *(fen + count) = 0;

}