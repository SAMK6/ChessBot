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


void bitBoardToFen(BitBoard board, char* fen){



}