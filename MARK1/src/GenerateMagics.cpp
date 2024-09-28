#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <random>
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
            indicies.push_back(i);
        }
    }

    return indicies;

}

// thie function generates all blocker bitboards for a square and then seperates them into a map
// the maps keys are valid attack sets, and the values vectors of blocker boards that lead to that attack set
map<uint64_t, vector<uint64_t>> seperateBlockers(uint8_t square, uint64_t pattern){

    uint64_t numPatterns = 1ull << __builtin_popcountll(pattern); // the number of blocker combos
    vector<int> indicies = patternIndicies(pattern); // the indicies of the bits in the pattern
    map<uint64_t, vector<uint64_t>> patternMap;
    uint64_t attacks, blockers;

    // first we need to organize the different patterns into the attack masks they map to
    for(int i = 0; i < numPatterns; i++){
        blockers = nth_blockerCombo(i, indicies);
        attacks = generateRookAttacks(square, blockers);

        if(patternMap.count(attacks)){
            patternMap[attacks].push_back(blockers);
        }
        else{
            patternMap[attacks] = vector<uint64_t>();
            patternMap[attacks].push_back(blockers);
        }
    }

    return patternMap;

}


uint64_t findMagics(uint8_t square, uint64_t pattern, int shift){

    map<uint64_t, vector<uint64_t>> patternMap = seperateBlockers(square, pattern);

    // now we should have a map where a given attack pattern for the rook maps to a vector of all the blocker patterns that give that attack pattern
    // generate a random magic number aiming at a 13 bit address space
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);

    uint64_t randomSparse, key, spaces;

    map<int, uint64_t> keys = map<int, uint64_t>();

newMagic:

    keys.clear();
    randomSparse = dist(gen) & dist(gen);

    // now we check if this number is magic
    for(const auto& pair : patternMap){

        for(const auto& blocks : pair.second){

            key = (randomSparse * blocks) >> shift;
            if(keys.count(key)){
                if(keys[key] != pair.first) goto newMagic;
            }
            else{
                keys[key] = pair.first;            
            }


        }

        cout << randomSparse << "  " << keys.size() << ":" << pair.second.size() << endl;

    }
    
    return randomSparse;

}

int testMagic(uint8_t square, uint64_t pattern, uint64_t magic){

    map<uint64_t, vector<uint64_t>> patternMap = seperateBlockers(square, pattern);



    return 1;

}


int main(int argc, char** argv){

    uint64_t board = generateRookMask(28);
    
    uint64_t magic = findMagics(28, board, 53);

    printf("%lu\n", magic);


    
}