#include <stdint.h>
#include "BitMasks.h"


uint64_t basicKnightMasks[64] = {
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

uint64_t basicBishopMasks[64] = {
    9241421688590303744ull,
    36099303471056128ull,
    141012904249856ull,
    550848566272ull,
    6480472064ull,
    1108177604608ull,
    283691315142656ull,
    72624976668147712ull,
    4620710844295151618ull,
    9241421688590368773ull,
    36099303487963146ull,
    141017232965652ull,
    1659000848424ull,
    283693466779728ull,
    72624976676520096ull,
    145249953336262720ull,
    2310355422147510788ull,
    4620710844311799048ull,
    9241421692918565393ull,
    36100411639206946ull,
    424704217196612ull,
    72625527495610504ull,
    145249955479592976ull,
    290499906664153120ull,
    1155177711057110024ull,
    2310355426409252880ull,
    4620711952330133792ull,
    9241705379636978241ull,
    108724279602332802ull,
    145390965166737412ull,
    290500455356698632ull,
    580999811184992272ull,
    577588851267340304ull,
    1155178802063085600ull,
    2310639079102947392ull,
    4693335752243822976ull,
    9386671504487645697ull,
    326598935265674242ull,
    581140276476643332ull,
    1161999073681608712ull,
    288793334762704928ull,
    577868148797087808ull,
    1227793891648880768ull,
    2455587783297826816ull,
    4911175566595588352ull,
    9822351133174399489ull,
    1197958188344280066ull,
    2323857683139004420ull,
    144117404414255168ull,
    360293502378066048ull,
    720587009051099136ull,
    1441174018118909952ull,
    2882348036221108224ull,
    5764696068147249408ull,
    11529391036782871041ull,
    4611756524879479810ull,
    567382630219904ull,
    1416240237150208ull,
    2833579985862656ull,
    5667164249915392ull,
    11334324221640704ull,
    22667548931719168ull,
    45053622886727936ull,
    18049651735527937ull
};

uint64_t basicRookMasks[64] = {
    72340172838076926ull,
    144680345676153597ull,
    289360691352306939ull,
    578721382704613623ull,
    1157442765409226991ull,
    2314885530818453727ull,
    4629771061636907199ull,
    9259542123273814143ull,
    72340172838141441ull,
    144680345676217602ull,
    289360691352369924ull,
    578721382704674568ull,
    1157442765409283856ull,
    2314885530818502432ull,
    4629771061636939584ull,
    9259542123273813888ull,
    72340172854657281ull,
    144680345692602882ull,
    289360691368494084ull,
    578721382720276488ull,
    1157442765423841296ull,
    2314885530830970912ull,
    4629771061645230144ull,
    9259542123273748608ull,
    72340177082712321ull,
    144680349887234562ull,
    289360695496279044ull,
    578721386714368008ull,
    1157442769150545936ull,
    2314885534022901792ull,
    4629771063767613504ull,
    9259542123257036928ull,
    72341259464802561ull,
    144681423712944642ull,
    289361752209228804ull,
    578722409201797128ull,
    1157443723186933776ull,
    2314886351157207072ull,
    4629771607097753664ull,
    9259542118978846848ull,
    72618349279904001ull,
    144956323094725122ull,
    289632270724367364ull,
    578984165983651848ull,
    1157687956502220816ull,
    2315095537539358752ull,
    4629910699613634624ull,
    9259541023762186368ull,
    143553341945872641ull,
    215330564830528002ull,
    358885010599838724ull,
    645993902138460168ull,
    1220211685215703056ull,
    2368647251370188832ull,
    4665518383679160384ull,
    9259260648297103488ull,
    18302911464433844481ull,
    18231136449196065282ull,
    18087586418720506884ull,
    17800486357769390088ull,
    17226286235867156496ull,
    16077885992062689312ull,
    13781085504453754944ull,
    9187484529235886208ull
};

uint64_t basicKingMasks[64] = {
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

uint64_t generateRookMask(uint8_t square){

    uint64_t mask = 0ull;

    uint8_t rank = square / (uint8_t)8;
    uint8_t file = square % (uint8_t)8;

    // first add the squares on the same rank
    for(uint8_t i = 0; i < (uint8_t)8; i++){
        if(i != rank){
            mask |= ((uint64_t)1 << ((uint8_t)8 * i + file));
        }
    }  
    
    //now add the squares on the same file
    for(uint8_t j = 0; j < (uint8_t)8; j++){
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
    while(offset <= up && offset <= left){

        mask |= (pos << (offset * (uint8_t)9));
        offset ++;

    }

    // next add squares to the top right of the bishop
    offset = (uint8_t)1;
    while(offset <= up && offset <= right){

        mask |= (pos << (offset * (uint8_t)7));
        offset ++;

    }

    // next add squares to the bottom left of the bishop
    offset = (uint8_t)1;
    while(offset <= down && offset <= left){

        mask |= (pos >> (offset * (uint8_t)7));
        offset ++;

    }

    // finally add squares to the bottom right of the bishop
    offset = (uint8_t)1;
    while(offset <= down && offset <= right){

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



