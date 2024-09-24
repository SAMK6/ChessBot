#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/Translator.h"
#include "../src/MoveGenerator.h"

int main(int argc, char** argv){

    char inputFEN[300], ourFEN[150], movedFEN[150];

    uint16_t move;

    char piece;

    BitBoard inputBoard, movedBoard;

    FILE *fp;

    fp = popen("bash -c 'source ../../test_data/chessENV/bin/activate && python3 ../../test_data/move_maker_test_data.py output.txt'", "r");

    if(fp == NULL){
        printf("error opening");
        return 1;
    }

    int processed = 0, wrong = 0;

    while(1){

        if (fgets(inputFEN, sizeof(inputFEN), fp) == NULL) {
            break;
        }

        inputFEN[strlen(inputFEN) - 1] = '\0';

        // Read the second line, expecting an integer followed by whitespace and then a char
        if (fscanf(fp, "%hu %c\n", &move, &piece) != 2) {
            break;
        }

        // Read the third line into buffer2
        if (fgets(movedFEN, sizeof(movedFEN), fp) == NULL) {
            break;
        }

        movedFEN[strlen(movedFEN) - 1] = '\0';

        processed ++;

        inputBoard = fenToBitBoard(inputFEN);

        movedBoard = makeMove(inputBoard, move, piece);

        bitBoardToFen(movedBoard, ourFEN);

        if(strcmp(ourFEN, movedFEN)){

            printf("Error with staring fen: %s\nmove: %hu\npiece: %c\nproduced: %s\nshould have been: %s\n\n", inputFEN, move, piece, ourFEN, movedFEN);
            wrong ++;

        }

        
    }

    printf("processed: %d\nwrong: %d\n", processed, wrong);

    // Close the file pointer
    pclose(fp);

    return 0;

}