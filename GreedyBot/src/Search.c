#include <stdint.h>
#include "Search.h"
#include "Evaluate.h"
#include "MoveGenerator.h"



SearchResult search(BitBoard board, int depth){

    SearchResult result;
    result.evaluation = INT_FAST32_MIN;

    if(depth == 0){
        result.evaluation = evaluate(board);
        return result;
    }

    uint64_t king =  *((uint64_t*)&board + 5 + 6 * !board.whiteToMove);
    uint8_t kingPos = __builtin_ctzll(king);

    if(isSquareAttacked(&board, kingPos)){ // if the king can be captured this position is invalid we return negative infinity
        result.evaluation = INT_FAST32_MIN;
        return result;
    }


    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);
    SearchResult eval;

    for(int i = 0; i < numMoves; i++){

        eval = search(makeMove(board, moves[i]), depth - 1);
        eval.evaluation *= -1;

        if(eval.evaluation > result.evaluation){
            result.evaluation = eval.evaluation;
            result.bestMove = moves[i];
        }

    }

    return result;

}