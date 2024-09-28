#include <stdint.h>
#include "BitMasks.h"


const uint64_t basicKnightMasks[64] = {
    132096ull,
    329728ull,
    659712ull,
    1319424ull,
    2638848ull,
    5277696ull,
    10489856ull,
    4202496ull,
    33816580ull,
    84410376ull,
    168886289ull,
    337772578ull,
    675545156ull,
    1351090312ull,
    2685403152ull,
    1075839008ull,
    8657044482ull,
    21609056261ull,
    43234889994ull,
    86469779988ull,
    172939559976ull,
    345879119952ull,
    687463207072ull,
    275414786112ull,
    2216203387392ull,
    5531918402816ull,
    11068131838464ull,
    22136263676928ull,
    44272527353856ull,
    88545054707712ull,
    175990581010432ull,
    70506185244672ull,
    567348067172352ull,
    1416171111120896ull,
    2833441750646784ull,
    5666883501293568ull,
    11333767002587136ull,
    22667534005174272ull,
    45053588738670592ull,
    18049583422636032ull,
    145241105196122112ull,
    362539804446949376ull,
    725361088165576704ull,
    1450722176331153408ull,
    2901444352662306816ull,
    5802888705324613632ull,
    11533718717099671552ull,
    4620693356194824192ull,
    288234782788157440ull,
    576469569871282176ull,
    1224997833292120064ull,
    2449995666584240128ull,
    4899991333168480256ull,
    9799982666336960512ull,
    1152939783987658752ull,
    2305878468463689728ull,
    1128098930098176ull,
    2257297371824128ull,
    4796069720358912ull,
    9592139440717824ull,
    19184278881435648ull,
    38368557762871296ull,
    4679521487814656ull,
    9077567998918656ull
};

const uint64_t basicBishopMasks[64] = {
    18049651735527936ull,
    70506452091904ull,
    275415828992ull,
    1075975168ull,
    38021120ull,
    8657588224ull,
    2216338399232ull,
    567382630219776ull,
    9024825867763712ull,
    18049651735527424ull,
    70506452221952ull,
    275449643008ull,
    9733406720ull,
    2216342585344ull,
    567382630203392ull,
    1134765260406784ull,
    4512412933816832ull,
    9024825867633664ull,
    18049651768822272ull,
    70515108615168ull,
    2491752130560ull,
    567383701868544ull,
    1134765256220672ull,
    2269530512441344ull,
    2256206450263040ull,
    4512412900526080ull,
    9024834391117824ull,
    18051867805491712ull,
    637888545440768ull,
    1135039602493440ull,
    2269529440784384ull,
    4539058881568768ull,
    1128098963916800ull,
    2256197927833600ull,
    4514594912477184ull,
    9592139778506752ull,
    19184279556981248ull,
    2339762086609920ull,
    4538784537380864ull,
    9077569074761728ull,
    562958610993152ull,
    1125917221986304ull,
    2814792987328512ull,
    5629586008178688ull,
    11259172008099840ull,
    22518341868716544ull,
    9007336962655232ull,
    18014673925310464ull,
    2216338399232ull,
    4432676798464ull,
    11064376819712ull,
    22137335185408ull,
    44272556441600ull,
    87995357200384ull,
    35253226045952ull,
    70506452091904ull,
    567382630219776ull,
    1134765260406784ull,
    2832480465846272ull,
    5667157807464448ull,
    11333774449049600ull,
    22526811443298304ull,
    9024825867763712ull,
    18049651735527936ull
};

const uint64_t basicRookMasks[64] = {
    282578800148862llu,
    565157600297596llu,
    1130315200595066llu,
    2260630401190006llu,
    4521260802379886llu,
    9042521604759646llu,
    18085043209519166llu,
    36170086419038334llu,
    282578800180736llu,
    565157600328704llu,
    1130315200625152llu,
    2260630401218048llu,
    4521260802403840llu,
    9042521604775424llu,
    18085043209518592llu,
    36170086419037696llu,
    282578808340736llu,
    565157608292864llu,
    1130315208328192llu,
    2260630408398848llu,
    4521260808540160llu,
    9042521608822784llu,
    18085043209388032llu,
    36170086418907136llu,
    282580897300736llu,
    565159647117824llu,
    1130317180306432llu,
    2260632246683648llu,
    4521262379438080llu,
    9042522644946944llu,
    18085043175964672llu,
    36170086385483776llu,
    283115671060736llu,
    565681586307584llu,
    1130822006735872llu,
    2261102847592448llu,
    4521664529305600llu,
    9042787892731904llu,
    18085034619584512llu,
    36170077829103616llu,
    420017753620736llu,
    699298018886144llu,
    1260057572672512llu,
    2381576680245248llu,
    4624614895390720llu,
    9110691325681664llu,
    18082844186263552llu,
    36167887395782656llu,
    35466950888980736llu,
    34905104758997504llu,
    34344362452452352llu,
    33222877839362048llu,
    30979908613181440llu,
    26493970160820224llu,
    17522093256097792llu,
    35607136465616896llu,
    9079539427579068672llu,
    8935706818303361536llu,
    8792156787827803136llu,
    8505056726876686336llu,
    7930856604974452736llu,
    6782456361169985536llu,
    4485655873561051136llu,
    9115426935197958144llu
};

const uint64_t basicKingMasks[64] = {
    770ull,
    1797ull,
    3594ull,
    7188ull,
    14376ull,
    28752ull,
    57504ull,
    49216ull,
    197123ull,
    460039ull,
    920078ull,
    1840156ull,
    3680312ull,
    7360624ull,
    14721248ull,
    12599488ull,
    50463488ull,
    117769984ull,
    235539968ull,
    471079936ull,
    942159872ull,
    1884319744ull,
    3768639488ull,
    3225468928ull,
    12918652928ull,
    30149115904ull,
    60298231808ull,
    120596463616ull,
    241192927232ull,
    482385854464ull,
    964771708928ull,
    825720045568ull,
    3307175149568ull,
    7718173671424ull,
    15436347342848ull,
    30872694685696ull,
    61745389371392ull,
    123490778742784ull,
    246981557485568ull,
    211384331665408ull,
    846636838289408ull,
    1975852459884544ull,
    3951704919769088ull,
    7903409839538176ull,
    15806819679076352ull,
    31613639358152704ull,
    63227278716305408ull,
    54114388906344448ull,
    216739030602088448ull,
    505818229730443264ull,
    1011636459460886528ull,
    2023272918921773056ull,
    4046545837843546112ull,
    8093091675687092224ull,
    16186183351374184448ull,
    13853283560024178688ull,
    144959613005987840ull,
    362258295026614272ull,
    724516590053228544ull,
    1449033180106457088ull,
    2898066360212914176ull,
    5796132720425828352ull,
    11592265440851656704ull,
    4665729213955833856ull
};

const uint64_t basicPawnMasksBlack[64] = {
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    2ull,
    5ull,
    10ull,
    20ull,
    40ull,
    80ull,
    160ull,
    64ull,
    512ull,
    1280ull,
    2560ull,
    5120ull,
    10240ull,
    20480ull,
    40960ull,
    16384ull,
    131072ull,
    327680ull,
    655360ull,
    1310720ull,
    2621440ull,
    5242880ull,
    10485760ull,
    4194304ull,
    33554432ull,
    83886080ull,
    167772160ull,
    335544320ull,
    671088640ull,
    1342177280ull,
    2684354560ull,
    1073741824ull,
    8589934592ull,
    21474836480ull,
    42949672960ull,
    85899345920ull,
    171798691840ull,
    343597383680ull,
    687194767360ull,
    274877906944ull,
    2199023255552ull,
    5497558138880ull,
    10995116277760ull,
    21990232555520ull,
    43980465111040ull,
    87960930222080ull,
    175921860444160ull,
    70368744177664ull,
    562949953421312ull,
    1407374883553280ull,
    2814749767106560ull,
    5629499534213120ull,
    11258999068426240ull,
    22517998136852480ull,
    45035996273704960ull,
    18014398509481984ull
};

const uint64_t basicPawnMasksWhite[64] = {
    512ull,
    1280ull,
    2560ull,
    5120ull,
    10240ull,
    20480ull,
    40960ull,
    16384ull,
    131072ull,
    327680ull,
    655360ull,
    1310720ull,
    2621440ull,
    5242880ull,
    10485760ull,
    4194304ull,
    33554432ull,
    83886080ull,
    167772160ull,
    335544320ull,
    671088640ull,
    1342177280ull,
    2684354560ull,
    1073741824ull,
    8589934592ull,
    21474836480ull,
    42949672960ull,
    85899345920ull,
    171798691840ull,
    343597383680ull,
    687194767360ull,
    274877906944ull,
    2199023255552ull,
    5497558138880ull,
    10995116277760ull,
    21990232555520ull,
    43980465111040ull,
    87960930222080ull,
    175921860444160ull,
    70368744177664ull,
    562949953421312ull,
    1407374883553280ull,
    2814749767106560ull,
    5629499534213120ull,
    11258999068426240ull,
    22517998136852480ull,
    45035996273704960ull,
    18014398509481984ull,
    144115188075855872ull,
    360287970189639680ull,
    720575940379279360ull,
    1441151880758558720ull,
    2882303761517117440ull,
    5764607523034234880ull,
    11529215046068469760ull,
    4611686018427387904ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull,
    0ull
};

uint64_t generateRookMask(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // first add the squares on the same rank
    for(uint8_t i = 1; i < (uint8_t)7; i++){
        if(i != rank){
            mask |= ((uint64_t)1 << ((uint8_t)8 * i + file));
        }
    }  
    
    //now add the squares on the same file
    for(uint8_t j = 1; j < (uint8_t)7; j++){
        if(j != file){
            mask |= (uint64_t)1 << ((uint8_t)8 * rank + j);
        }
    }

    return mask;

}



uint64_t generateBishopMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;
    
    uint8_t left = (uint8_t)7 - file;
    uint8_t right = file;
    uint8_t up = (uint8_t)7 - rank;
    uint8_t down = rank;

    // first add squares to the top left of the bishop
    uint8_t offset = (uint8_t)1;
    while(offset < up && offset < left){

        mask |= (pos << (offset * (uint8_t)9));
        offset ++;

    }

    // next add squares to the top right of the bishop
    offset = (uint8_t)1;
    while(offset < up && offset < right){

        mask |= (pos << (offset * (uint8_t)7));
        offset ++;

    }

    // next add squares to the bottom left of the bishop
    offset = (uint8_t)1;
    while(offset < down && offset < left){

        mask |= (pos >> (offset * (uint8_t)7));
        offset ++;

    }

    // finally add squares to the bottom right of the bishop
    offset = (uint8_t)1;
    while(offset < down && offset < right){

        mask |= (pos >> (offset * (uint8_t)9));
        offset ++;

    }

    return mask;

}


uint64_t generateKnightMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // each of these staementas makes sure the knight is far enough away from the edge of the board for any of its 8 possible moves
    if(rank < (uint8_t)7 && file < (uint8_t)6) mask |= (pos << 10);

    if(rank < (uint8_t)6 && file < (uint8_t)7) mask |= (pos << 17);

    if(rank < (uint8_t)6 && file > (uint8_t)0) mask |= (pos << 15);

    if(rank < (uint8_t)7 && file > (uint8_t)1) mask |= (pos << 6);

    if(rank > (uint8_t)0 && file > (uint8_t)1) mask |= (pos >> 10);

    if(rank > (uint8_t)1 && file > (uint8_t)0) mask |= (pos >> 17);

    if(rank > (uint8_t)1 && file < (uint8_t)7) mask |= (pos >> 15);

    if(rank > (uint8_t)0 && file < (uint8_t)6) mask |= (pos >> 6);

    return mask;

}


uint64_t generateQueenMask(uint8_t square){

    return generateRookMask(square) | generateBishopMask(square);

}


uint64_t generateKingMask(uint8_t square){

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    if(rank != (uint8_t)7){ // check if the king it at the top of the board

        mask |= (pos << 8);

        if(file != (uint8_t)7){
            mask |= (pos << 9);
            mask |= (pos << 1);
        }
        if(file != (uint8_t)0){
            mask |= (pos << 7);
            mask |= (pos >> 1);
        }

    }

    if(rank != (uint8_t)0){ // check if the king is at the bottom of the board

        mask |= (pos >> 8);

        if(file != (uint8_t)7){
            mask |= (pos >> 7);
            mask |= (pos << 1);
        }
        if(file != (uint8_t)0){
            mask |= (pos >> 9);
            mask |= (pos >> 1);
        }

    }

    return mask;

}

uint64_t generatePawnMaskBlack(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t file = square % (uint8_t)8;

    if(file < 7) mask |= (1ull << square) >> 7;

    if(file > 0) mask |= (1ull << square) >> 9;

    return mask;

}

uint64_t generatePawnMaskWhite(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t file = square % (uint8_t)8;

    if(file < 7) mask |= (1ull << square) << 9;

    if(file > 0) mask |= (1ull << square) << 7;

    return mask;

}

uint64_t generateBishopAttacks(uint8_t square, uint64_t pieces){

    uint64_t blockers = pieces & basicBishopMasks[square];
    
    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    int rank = (int)(square / (uint8_t)8);
    int file = (int)(square % (uint8_t)8);

    // add the attacked squares to the top left
    int offset = 1;
    while(rank + offset < 8 && file + offset < 8){

        mask |= pos << (9 * offset);

        if((pos << (9 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the top right
    offset = 1;
    while(rank + offset < 8 && file - offset >= 0){

        mask |= pos << (7 * offset);

        if((pos << (7 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the bottom right
    offset = 1;
    while(rank - offset >= 0 && file - offset >= 0){

        mask |= pos >> (9 * offset);

        if((pos >> (9 * offset)) & blockers) break;

        offset++;

    }

    // add the attacked squares to the bottom left
    offset = 1;
    while(rank - offset >= 0 && file + offset < 8){

        mask |= pos >> (7 * offset);

        if((pos >> (7 * offset)) & blockers) break;

        offset++;

    }
    
    return mask;
    
}

uint64_t generateRookAttacks(uint8_t square, uint64_t pieces){

    uint64_t blockers = pieces & basicRookMasks[square];

    uint64_t mask = 0ull;
    uint64_t pos = (uint64_t)1 << square;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;


    // squares the rook attacks above the rook
    for(int i = (int)rank + 1; i < 8; i++){

        mask |= (pos << (8 * (i - rank)));

        if((pos << (8 * (i - rank))) & blockers) break;

    }
    
    // squares below the rook
    for(int i = (int)rank - 1; i >= 0; i--){

        mask |= (pos >> (8 * (rank - i)));

        if((pos >> (8 * (rank - i))) & blockers) break;

    }

    // squares to thr right of the rook
    for(int i = (int)file - 1; i >= 0; i--){

        mask |= (pos >> (file - i));
        if((pos >> (file - i)) & blockers) break;

    }

    // squares to thr left of the rook
    for(int i = (int)file + 1; i < 8; i++){

        mask |= (pos << (i - file));
        if((pos << (i - file)) & blockers) break;

    }

    return mask;

}



