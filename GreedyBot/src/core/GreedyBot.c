#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"

char *startposFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
BitBoard board; // this will be the board for the engine, later this may become an engine struct that can include things like a hash table etc

int main(int argc, char** argv){

    printf("GreedyBot v0.0 by Sam Feldman\n\n");
    setbuf(stdout, NULL); // idk what this does but it worked
    static char buffer[3000]; // used to store the input

    // used to aid in tokenizing the input
    char *curr;
    int numTokens;
    char *tokens[300];

    FILE *fp = fopen("output.txt", "w");

    while(1){

        if(fgets(buffer, 3000, stdin) != NULL){

            buffer[strlen(buffer) - 1] = '\0';

            fprintf(fp, "%s\n", buffer);

            // reset the token stuff
            curr = strtok(buffer, " ");
            numTokens = 0;

            // tokenize the input in place
            while(curr != NULL) {
                tokens[numTokens++] = curr; 
                curr = strtok(NULL, " \t\n\r\v\f");
            }
            
            for(int i = 0; i < numTokens; i++){

                if(!strcmp(tokens[i], "uci")){
                    printf("id name GreedyBot\nid author Sam Feldman\nuciok\n");
                    break;
                }
                else if(!strcmp(tokens[i], "debug")){
                    // no debug mode yet so do nothing
                    break;
                }
                else if(!strcmp(tokens[i], "isready")){
                    printf("readyok\n");
                    break;
                }
                else if(!strcmp(tokens[i], "setoption")){
                    printf("Option not recognized.\n");
                    break;
                }
                else if(!strcmp(tokens[i], "register")){
                    printf("later");
                    break;
                }
                else if(!strcmp(tokens[i], "ucinewgame")){
                    // reset all the state info and stuff like that
                    // will implement this once I have a better idea of what needs to be stored
                    // clearing hashes and stuff like that
                    break;
                }
                else if(!strcmp(tokens[i], "position")){
                    
                    if(!strcmp(tokens[i + 1], "fen")){
                        if(numTokens < (i + 8)){
                            printf("Not enough arguments for a fen string. Need: pieces, turn, castling rights, en passant, hafmoves, and moves.\n");
                            break;
                        }
                        char inputFEN[120];
                        sprintf(inputFEN, "%s %s %s %s %s %s", tokens[i + 2], tokens[i + 3], tokens[i + 4], tokens[i + 5], tokens[i + 6], tokens[i + 7]);
                        board = fenToBitBoard(inputFEN);
                        
                        if(numTokens > (i + 8) && !strcmp(tokens[i + 8], "moves")){ // start processing moves
                            for(int j = i + 9; j < numTokens; j++){
                                Move move = uciToMove(&board, tokens[j]);
                                makeMove(&board, move);
                            }
                        }
                    }
                    else if(!strcmp(tokens[i + 1], "startpos")){
                        board = fenToBitBoard(startposFEN);
                        if(numTokens > (i + 2) && !strcmp(tokens[i + 2], "moves")){ // start processing moves
                            for(int j = i + 3; j < numTokens; j++){
                                Move move = uciToMove(&board, tokens[j]);
                                makeMove(&board, move);
                            }
                        }
                    }
                    else{
                        printf("Position command not understood.\n");
                    }

                    break;
                }
                else if(!strcmp(tokens[i], "go")){

                    Move result = bestMove(board);
                    
                    char moveToPlay[6];
                    moveToUCI(result, moveToPlay);

                    printf("bestmove %s\n", moveToPlay);

                    break;
                }
                else if(!strcmp(tokens[i], "stop")){
                    // send some signal to the searching thread
                    break;
                }
                else if(!strcmp(tokens[i], "ponderhit")){
                    // idk not gonna worry about this for now
                    break;
                }
                else if(!strcmp(tokens[i], "quit")){
                    exit(0);
                }
                else{
                    printf("Unknown command.\n");
                    break;
                }

            }

        }

    }

    fclose(fp);

}