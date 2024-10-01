#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "BitMasks.h"

using namespace std;

int numBishopBlockers[64] = {
    64,
    32,
    32,
    32,
    32,
    32,
    32,
    64,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    128,
    128,
    128,
    128,
    32,
    32,
    32,
    32,
    128,
    512,
    512,
    128,
    32,
    32,
    32,
    32,
    128,
    512,
    512,
    128,
    32,
    32,
    32,
    32,
    128,
    128,
    128,
    128,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    32,
    64,
    32,
    32,
    32,
    32,
    32,
    32,
    64
};

int bishopOffSets[64] = {
    0,
    64,
    96,
    128,
    160,
    192,
    224,
    256,
    320,
    352,
    384,
    416,
    448,
    480,
    512,
    544,
    576,
    608,
    640,
    768,
    896,
    1024,
    1152,
    1184,
    1216,
    1248,
    1280,
    1408,
    1920,
    2432,
    2560,
    2592,
    2624,
    2656,
    2688,
    2816,
    3328,
    3840,
    3968,
    4000,
    4032,
    4064,
    4096,
    4224,
    4352,
    4480,
    4608,
    4640,
    4672,
    4704,
    4736,
    4768,
    4800,
    4832,
    4864,
    4896,
    4928,
    4992,
    5024,
    5056,
    5088,
    5120,
    5152,
    5184
};

int rookOffsets[64] = {
    0,
    4096,
    6144,
    8192,
    10240,
    12288,
    14336,
    16384,
    20480,
    22528,
    23552,
    24576,
    25600,
    26624,
    27648,
    28672,
    30720,
    32768,
    33792,
    34816,
    35840,
    36864,
    37888,
    38912,
    40960,
    43008,
    44032,
    45056,
    46080,
    47104,
    48128,
    49152,
    51200,
    53248,
    54272,
    55296,
    56320,
    57344,
    58368,
    59392,
    61440,
    63488,
    64512,
    65536,
    66560,
    67584,
    68608,
    69632,
    71680,
    73728,
    74752,
    75776,
    76800,
    77824,
    78848,
    79872,
    81920,
    86016,
    88064,
    90112,
    92160,
    94208,
    96256,
    98304
};

int numRookBlockers[64] = {
    4096ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    4096ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    2048ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    1024ull,
    2048ull,
    4096ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    2048ull,
    4096ull
};

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
map<uint64_t, vector<uint64_t> > seperateRookBlockers(uint8_t square){

    uint64_t pattern = generateRookMask(square);

    uint64_t numPatterns = 1ull << __builtin_popcountll(pattern); // the number of blocker combos
    vector<int> indicies = patternIndicies(pattern); // the indicies of the bits in the pattern
    map<uint64_t, vector<uint64_t> > patternMap;
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

map<uint64_t, vector<uint64_t> > seperateBishopBlockers(uint8_t square){

    uint64_t pattern = generateBishopMask(square);

    uint64_t numPatterns = 1ull << __builtin_popcountll(pattern); // the number of blocker combos
    vector<int> indicies = patternIndicies(pattern); // the indicies of the bits in the pattern
    map<uint64_t, vector<uint64_t> > patternMap;
    uint64_t attacks, blockers;

    // first we need to organize the different patterns into the attack masks they map to
    for(int i = 0; i < numPatterns; i++){
        blockers = nth_blockerCombo(i, indicies);
        attacks = generateBishopAttacks(square, blockers);

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


map<int, uint64_t> findMagics(uint8_t square, int shift, uint64_t *magics){

    map<uint64_t, vector<uint64_t> > patternMap;

    // now we should have a map where a given attack pattern for the rook maps to a vector of all the blocker patterns that give that attack pattern
    // generate a random magic number aiming at a 13 bit address space
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);

    uint64_t magic, key;

    map<int, uint64_t> keys = map<int, uint64_t>();


    patternMap = seperateBishopBlockers(square);

newMagic:

    keys.clear();

    magic = dist(gen) & dist(gen);

    for(const auto& pair : patternMap){

        for(const auto& blocks : pair.second){

            key = (magic * blocks) >> shift;
            if(keys.count(key) && keys[key] != pair.first){
                goto newMagic;
            }
            else{
                keys[key] = pair.first;
            }
        }

        //cout << magic << " : " << keys.size() << endl;


    }

    *(magics) = magic;

    //cout << magic << endl;
    
    return keys;

}



int main(int argc, char** argv){

    uint64_t magics[64];

    

    uint64_t *attacks = (uint64_t*)malloc(5248 * sizeof(uint64_t));

    map<int, uint64_t> keys;
    
    for(int i = 0; i < 64; i++){

        int bits = 64 - __builtin_popcountll(generateBishopMask(i));

        keys = findMagics(i, bits, (magics + i));


        for(const auto& pair : keys){

            attacks[pair.first + bishopOffSets[i]] = pair.second;

        }

    }


    for(int i = 0; i < 5248; i++){
        printf("%luull,\n", attacks[i]);
    }

    printf("\n");

    for(int i = 0; i < 64; i++){
        printf("%lullu,\n", magics[i]);
    }


    return 0;


    
}