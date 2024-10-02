#include <stdint.h>
#include "BitBoard.h"
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
    // if the king can be captured this position is invalid we return infinity because capturing the king is the best move always
    if(isSquareAttacked(&board, kingPos)){ 
        result.evaluation = INT_FAST32_MAX;
        return result;
    }


    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);
    SearchResult eval;
    BitBoard newBoard;

    for(int i = 0; i < numMoves; i++){

        newBoard = board;
        makeMove(&newBoard, moves[i]);

        eval = search(newBoard, depth - 1);
        eval.evaluation *= -1;

        if(eval.evaluation > result.evaluation){
            result.evaluation = eval.evaluation;
            result.bestMove = moves[i];
        }

    }

    return result;

}