#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "MoveGenerator.h"
#include "BitBoard.h"
#include "Search.h"
#include "Translator.h"


// writing this UCI stuff is gonna end up being a test of my regex skills
int main(int argc, char** argv){

    char buffer[151];

    while(1){

        if(fgets(buffer, 151, stdin)){

            printf("%s\n", buffer);

            if(!strcmp(buffer, "quit\n")){
                exit(0);
            }

        }

    }

}