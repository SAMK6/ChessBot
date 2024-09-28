#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <map>
#include "BitBoard.h"
#include "BitMasks.h"

using namespace std;

uint64_t nth_blockerCombo(int n, vector<int>& indicies){

    uint64_t combo = 0ull;

    for(int i = 0; i < 64; i++){
        if((1ull << i) & n){
            combo |= 1ull << indicies.at(i);
        }
    }

    return combo;

}

vector<int> patternIndicies(uint64_t board){

    vector<int> indicies;

    for(int i = 0; i < 64; i++){
        if(board & (1ull << i)){
            indicies.insert(indicies.begin(), i);
        }
    }

    return indicies;

}

uint64_t findMagic(uint64_t square, )


int main(int argc, char** argv){

    uint64_t board = generateRookMask(28);

    vector<int> indicies = patternIndicies(board);

    for(int i = 0; i < (1ull << __builtin_popcountll(board)); i++){

        printBitBoard64(nth_blockerCombo(i, indicies));

    }


    
}