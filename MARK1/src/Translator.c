#include "Translator.h"


BitBoard fenToBitBoard(const char* fen){

    // first we process the actual board position until we have seen 7 '/' characters

    BitBoard position = {(Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (Bint)0, (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned short)0, (Bint)0};

    int count = 0, pos = 63;

    char curr;

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
            default: // there is a problem if we reach here
                break;
        }

        count++;

    } while(curr != ' ');




    return position;

}


void bitBoardToFen(BitBoard board, char* fen){



}