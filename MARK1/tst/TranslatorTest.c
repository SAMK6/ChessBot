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

    int count = 1, wrong = 0;
    
    while(fgets(fen, sizeof(fen), file) != NULL) {
        // Remove the newline character
        newline_ptr = strchr(fen, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }
        
        BitBoard board = fenToBitBoard(fen);

        char* myFen = malloc(100*sizeof(char));

        bitBoardToFen(board, myFen);

        if(strcmp(fen, myFen)){
            printf("%d\n", count);
            wrong++;

            printf("%s\n%s\n", fen, myFen);
        }


        count ++;

    }

    printf("\nwrong: %d\nFENs processed: %d\n", wrong, count);



    fclose(file);
    return 0;
}