#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/core/BitBoard.h"
#include "../src/core/Translator.h"
#include "../src/core/MoveGenerator.h"

/*
    whatever FEN is at the first line of the input textfile will always fail because of txt file weirdness,
    since we know the starting position works the starting position is at the start of the file,
    it fails this test but we ignore it
*/


int main(int argc, char** argv){

    FILE *file;
    char fen[100];
    char *newline_ptr;

    // Open the file in read mode
    file = fopen("data/translator_test_data.txt", "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    int count = 0, wrong = 0;

    printf("Testing board translator\n");

    while(fgets(fen, sizeof(fen), file) != NULL) {
        // Remove the newline character
        newline_ptr = strchr(fen, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }

        BitBoard board = fenToBitBoard(fen);

        char* myFen = malloc(100*sizeof(char));

        bitBoardToFen(board, myFen);

        if(strcmp(fen, myFen) || !validBitBoard(board)){

            printf("Error with FEN: %d\n\n", count);

            if(strcmp(fen, myFen)){
                printf("input: %s\noutput: %s\n", fen, myFen);
            }

            if(!validBitBoard(board)){
                debugPrintBitBoard(board);
            }

            printf("\n");

            wrong++;

        }


        count ++;

    }

    printf("FENs processed: %d\nwrong: %d\n\n", count, wrong);
    fclose(file);


    // Open the file in read mode again
    file = fopen("data/translator_test_data.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    printf("Testing move translator\n");

    count = 0;
    wrong = 0;

    char UCImove[6];
    Move tempMove;
    BitBoard tempBoard;

    while(fgets(fen, sizeof(fen), file) != NULL) {
        // Remove the newline character
        newline_ptr = strchr(fen, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }

        BitBoard board = fenToBitBoard(fen);

        Move moves[256];

        int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

        for(int i = 0; i < numMoves; i++){

            // first we check if this is a valid move
            tempBoard = board;
            makeMove(&tempBoard, moves[i]);
            uint64_t king =  tempBoard.whiteToMove ? tempBoard.black.k : tempBoard.white.k;
            uint8_t kingPos = __builtin_ctzll(king);

            if(!isSquareAttacked(&(tempBoard), kingPos)){

                count++;

                moveToUCI(moves[i], UCImove);

                tempMove = uciToMove(&board, UCImove);

                if(tempMove != moves[i]){
                    wrong++;
                    printf("Error with FEN: %s. Move: %u\nProduced: %u, and %s\n", fen, moves[i], tempMove, UCImove);
                }


            }


        }

    }

    printf("FENs processed: %d\nwrong: %d\n", count, wrong);
    fclose(file);


    return 0;
}
