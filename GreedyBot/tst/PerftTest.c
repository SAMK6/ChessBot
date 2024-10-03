#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/core/BitBoard.h"
#include "../src/core/Translator.h"
#include "../src/core/MoveGenerator.h"





/*
    test positions and results taken from CPW https://www.chessprogramming.org/Perft_Results
    these tests serves as both performance and correcness tests
*/

uint64_t startPosition[7] = {1ull, 20ull, 400ull, 8902ull, 197281ull, 4865609ull, 119060324ull};
uint64_t position2[7] = {1ull, 48ull, 2039ull, 97862ull, 4085603ull, 193690690ull, 8031647685ull};
uint64_t position3[9] = {1ull, 14ull, 191ull, 2812ull, 43238ull, 674624ull, 11030083ull, 178633661ull, 3009794393ull};
uint64_t position4[7] = {1ull, 6ull, 264ull, 9467ull, 422333ull, 15833292ull, 706045033ull};
uint64_t position5[6] = {1ull, 44ull, 1486ull,  62379ull, 2103487ull, 89941194ull};

char *start = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char *pos2 = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
char *pos3 = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1";
char *pos4 = "r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1";
char *pos5 = "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8";



uint64_t perft(BitBoard board, int depth){

    if(depth == 0) return 1ull;

    Move moves[100];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);
    BitBoard newBoard = board;
    uint64_t positions = 0ull;

    for(int i = 0; i < numMoves; i++){
        
        newBoard = board;
        makeMove(&newBoard, moves[i]);

        uint8_t kingPos = (uint8_t)__builtin_ctzll(newBoard.whiteToMove ? newBoard.black.k : newBoard.white.k);
        if(!isSquareAttacked(&(newBoard), kingPos)) positions += (depth == 1) ? 1 : perft(newBoard, depth - 1);

    }
  
    return positions;

}

int main(int argc, char** argv){

    BitBoard board = fenToBitBoard(start);

    uint64_t ans;

    printf("PERFT TESTS\n\n");
    for(int i = 0; i < 7; i++){

        ans = perft(board, i);
       
        if(ans != startPosition[i]){
            printf("Error with start position\ninput: %d\nReturned: %lu\nShould have been: %lu\n", i, ans, startPosition[i]);
            break;
        }

    }

    board = fenToBitBoard(pos2);

    for(int i = 0; i < 6; i++){

        ans = perft(board, i);
       
        if(ans != position2[i]){
            printf("Error with position 2\ninput: %d\nReturned: %lu\nShould have been: %lu\n", i, ans, position2[i]);
            break;
        }

    }
    
    board = fenToBitBoard(pos3);

    for(int i = 0; i < 7; i++){

        ans = perft(board, i);
       
        if(ans != position3[i]){
            printf("Error with position 3\ninput: %d\nReturned: %lu\nShould have been: %lu\n", i, ans, position3[i]);
            break;
        }

    }

    board = fenToBitBoard(pos4);

    for(int i = 0; i < 7; i++){

        ans = perft(board, i);
       
        if(ans != position4[i]){
            printf("Error with position 4\ninput: %d\nReturned: %lu\nShould have been: %lu\n", i, ans, position4[i]);
            break;
        }

    }

    board = fenToBitBoard(pos5);

    for(int i = 0; i < 6; i++){

        ans = perft(board, i);
       
        if(ans != position5[i]){
            printf("Error with position 6\ninput: %d\nReturned: %lu\nShould have been: %lu\n", i, ans, position5[i]);
            break;
        }

    }


}