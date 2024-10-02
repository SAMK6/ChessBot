#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"


int main(int argc, char** argv){

    char buffer[300]; // used to store the input

    // used to aid in tokenizing the input
    char *curr;
    int numTokens;
    char *tokens[30];

    while(1){

        if(fgets(buffer, 300, stdin)){

            buffer[strlen(buffer) - 1] = '\0';

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
                }
                else if(!strcmp(tokens[i], "debug")){
                    // no debug mode yet
                }
                else if(!strcmp(tokens[i], "isready")){
                    printf("readyok\n");
                }
                else if(!strcmp(tokens[i], "setoption")){
                    // nothing for now
                }
                else if(!strcmp(tokens[i], "register")){
                    // idk
                }
                else if(!strcmp(tokens[i], "ucinewgame")){
                    // reset all the state info and stuff like that
                }
                else if(!strcmp(tokens[i], "position")){
                    // this is gonna be a real pain to implement i should have looked at the uci earlier
                }
                else if(!strcmp(tokens[i], "go")){
                    // call search
                }
                else if(!strcmp(tokens[i], "stop")){
                    // maybe some innterupt
                }
                else if(!strcmp(tokens[i], "ponderhit")){
                    // idk
                }
                else if(!strcmp(tokens[i], "quit")){
                    exit(0);
                }

            }

        }

    }

}