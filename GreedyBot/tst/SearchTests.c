#include <stdint.h>
#include <stdio.h>
#include "../src/core/Search.h"
#include "../src/core/Translator.h"


int main(){

    // this is a test for time simply call with time argument to get system time

    uint64_t numNodes = 0ull;


    char *FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard board = fenToBitBoard(FEN);

    bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);

    numNodes = 0ull;


    FEN = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

    board = fenToBitBoard(FEN);

    bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);

    numNodes = 0ull;


    FEN = "r2qk2r/p1p2ppp/1pnbpn2/3p2B1/3P2b1/1PNBPN2/P1P2PPP/R2QK2R b KQkq - 0 1";

    board = fenToBitBoard(FEN);

    bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);
    
    numNodes = 0ull;


    FEN = "r2qk2r/p1p2ppp/1pnbpn2/3p2B1/3P2b1/1PNBPN2/P1P2PPP/R2QK2R w KQkq - 0 1";

    board = fenToBitBoard(FEN);

    bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);

}