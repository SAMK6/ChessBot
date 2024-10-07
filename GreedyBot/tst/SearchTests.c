#include <stdint.h>
#include <stdio.h>
#include "../src/core/Search.h"
#include "../src/core/Translator.h"


int main(){

    // this is a test for time simply call with time argument to get system time

    uint64_t numNodes = 0;


    char *FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    BitBoard board = fenToBitBoard(FEN);

    Move irrelevent = bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);



    FEN = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

    board = fenToBitBoard(FEN);

    irrelevent = bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);



    FEN = "rn1k1b1r/pbpp1Q1p/1p2p3/7B/3PP2q/P1N5/1PP2PPP/R3K2R b KQ - 0 12";

    board = fenToBitBoard(FEN);

    irrelevent = bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);



    FEN = "r2k1b1r/pbpp1Q1p/1pn1p3/7B/3PP2q/P1N5/1PP2PPP/R3K2R w KQ - 1 13";

    board = fenToBitBoard(FEN);

    irrelevent = bestMove(board, 6, &numNodes);

    printf("Position: %s\nNodes %lu\n", FEN, numNodes);


}