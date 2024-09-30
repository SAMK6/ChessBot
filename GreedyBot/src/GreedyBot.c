#include <stdio.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"


int main(int argc, char** argv){

    if(argc != 7) printf("Please enter a valid FEN\n");

    char FEN[150];
    
    int fenSize = sprintf(FEN, "%s %s %s %s %s %s", argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);

    if(fenSize > 149) printf("oops\n");
    
    BitBoard board = fenToBitBoard(FEN);

    SearchResult move = search(board, 6);

    printf("%d to %d\n", move.bestMove & startMask, (move.bestMove & endMask) >> 6);

}