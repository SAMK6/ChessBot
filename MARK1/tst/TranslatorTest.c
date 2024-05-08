#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/BitBoard.h"
#include "../src/Translator.h"

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
    file = fopen("output.txt", "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }

    int count = 0, wrong = 0;

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

    printf("FENs processed: %d\nwrong: %d\n", count, wrong);



    fclose(file);
    return 0;
}
