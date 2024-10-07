#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"


// default vals
char *startposFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


// this will be the board for the engine, later this may become an engine struct that can include things like a hash table etc
BitBoard board; 
Move chosenMove;
int depth = 0, doneThinking = 0, isThinking = 0;
uint64_t numNodes = 0ull;


// thread stuff
pthread_t searchThread;
pthread_mutex_t lock;


void* handleGo(void* args){


    Move result = bestMove(board, 6, &numNodes);

    *((Move*)args) = result;


    doneThinking = 1;
    isThinking = 0;

    pthread_exit(NULL);

}


int main(int argc, char** argv){

    printf("GreedyBot v0.0 by Sam Feldman\n\n");
    static char buffer[3000]; // used to store the input

    // used to aid in tokenizing the input
    char *curr;
    int numTokens, numCommands;
    char *commands[10];
    char *tokens[300];

    // for setting stdin to non blocking
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    // idk what this does but it worked for not buffering outputs and sending them straight to the GUI
    setbuf(stdout, NULL);

    while(1){

        if(doneThinking){

            pthread_join(searchThread, NULL);

            char uciMove[6];

            moveToUCI(chosenMove, uciMove);

            printf("info nodes %lu\n", numNodes);
            printf("bestmove %s\n", uciMove);

            doneThinking = 0;
            numNodes = 0;
            isThinking = 0;

        }

        if(isThinking){
            printf("info nodes %lu\n", numNodes);
        }

        int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

        if(n > 0){

            buffer[n - 1] = '\0';

            // first we tokenize by newlines to seperate the commands
            curr = strtok(buffer, "\n");
            numCommands = 0;

            // tokenize the input in place
            while(curr != NULL) {
                commands[numCommands++] = curr; 
                curr = strtok(NULL, "\n");
            }

            for(int j = 0; j < numCommands; j++){

                curr = strtok(commands[j], " \t\r\v\f");
                numTokens = 0;

                // tokenize the input in place
                while(curr != NULL) {
                    tokens[numTokens++] = curr; 
                    curr = strtok(NULL, " \t\r\v\f");
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

                        if(numTokens < 2){
                            printf("Position command without position argument.\n");
                            break;
                        }
                        
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

                        pthread_create(&searchThread, NULL, handleGo, (void*)&chosenMove);

                        isThinking = 1;

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
            
        usleep(50000);

    }

}