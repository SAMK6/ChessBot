#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../src/core/BitBoard.h"
#include "../src/core/Translator.h"
#include "../src/core/MoveGenerator.h"

int main(int argc, char** argv){

    char inputFEN[300], ourFEN[300], movedFEN[300];

    uint32_t move;

    char piece;

    size_t offset;

    BitBoard inputBoard, movedBoard;

    FILE *fp;

        printf("TESTING MOVE MAKER\n");

    //fp = popen("bash -c 'source ../../test_data/chessENV/bin/activate && python3 ../../test_data/move_maker_test_data.py translator_test_data.txt'", "r");
    fp = fopen("data/move_maker_data.txt", "r");


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
        if (fscanf(fp, "%u %c\n", &move, &piece) != 2) {
            break;
        }

        // Read the third line into buffer2
        if (fgets(movedFEN, sizeof(movedFEN), fp) == NULL) {
            break;
        }

        movedFEN[strlen(movedFEN) - 1] = '\0';

        switch(piece){
            case 'p':
                move |= 0 << 16;
                break;
            case 'n':
                move |= 1 << 16;
                break;
            case 'b':
                move |= 2 << 16;
                break;
            case 'r':
                move |= 3 << 16;
                break;
            case 'q':
                move |= 4 << 16;
                break;
            case 'k':
                move |= 5 << 16;
                break;
            case 'P':
                move |= 6 << 16;
                break;
            case 'N':
                move |= 7 << 16;
                break;
            case 'B':
                move |= 8 << 16;
                break;
            case 'R':
                move |= 9 << 16;
                break;
            case 'Q':
                move |= 10 << 16;
                break;
            case 'K':
                move |= 11 << 16;
                break;

        }

        processed ++;

        inputBoard = fenToBitBoard(inputFEN);

        movedBoard = makeMove(inputBoard, move);

        bitBoardToFen(movedBoard, ourFEN);

        if(strcmp(ourFEN, movedFEN)){

            printf("Error with staring fen: %s\nmove: %hu\npiece: %c\nproduced: %s\nshould have been: %s\n\n", inputFEN, move, piece, ourFEN, movedFEN);
            wrong ++;

        }

        
    }

    printf("processed: %d\nwrong: %d\n", processed, wrong);

    // Close the file pointer
    pclose(fp);




    printf("\n\nTESTING MOVE GENERATOR\n");
    fp = fopen("data/move_generator_data.txt", "r");


    if(fp == NULL){
        printf("error opening");
        return 1;
    }

    int numMovesReal, numMovesMine, numMovesGen;
    processed = 0;
    wrong = 0;

    while(1){


        if (fgets(inputFEN, sizeof(inputFEN), fp) == NULL) {
            break;
        }

        inputFEN[strlen(inputFEN) - 1] = '\0';

        // Read the second line, expecting an integer followed by whitespace and then a char
        if (fscanf(fp, "%d\n", &numMovesReal) != 1) {
            break;
        }

        inputBoard = fenToBitBoard(inputFEN);

        Move *moves = (Move*)malloc(400 * sizeof(Move));

        if(moves == NULL) continue;

        processed++;

        numMovesMine = inputBoard.whiteToMove ? generateMovesWhite(&inputBoard, moves) : generateMovesBlack(&inputBoard, moves);
        
        numMovesGen = numMovesMine;

        BitBoard position;

        for(int i = 0; i < numMovesMine; i++){

            position = makeMove(inputBoard, *(moves + i));

            uint64_t king =  position.whiteToMove ? position.black.k : position.white.k;
            uint8_t kingPos = __builtin_ctzll(king);

            if(isSquareAttacked(&(position), kingPos)){
                numMovesGen--;
            }

        }

        if(numMovesGen != numMovesReal){

            printf("Error with: %s\nGenerated: %d moves\nShould have been: %d moves\n\n", inputFEN, numMovesGen, numMovesReal);
            wrong++;

        }


        free(moves);
        

    }

    printf("processed: %d\nwrong: %d\n", processed, wrong);


    return 0;

}