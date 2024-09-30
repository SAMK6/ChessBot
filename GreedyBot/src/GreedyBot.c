#include <stdio.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"


int main(int argc, char** argv){

    char *FEN = "2r1rk2/1b1qpp1p/3p2p1/1ppP2P1/2P1RP2/1BPP3P/4Q3/4R1K1 b - - 0 29";
    BitBoard board = fenToBitBoard(FEN);

    SearchResult move = search(board, 6);

    printf("%d to %d\n", move.bestMove & startMask, (move.bestMove & endMask) >> 6);

}