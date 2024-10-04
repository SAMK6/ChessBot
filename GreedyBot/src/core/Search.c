#include <stdint.h>
#include "BitBoard.h"
#include "Search.h"
#include "Evaluate.h"
#include "MoveGenerator.h"


Move bestMove(BitBoard board){

    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    uint8_t kingPos;
    BitBoard temp;
    int_fast32_t eval, bestEval = INT_FAST32_MIN;

    Move bestMove;

    for(int i = 0; i < numMoves; i++){

        temp = board;
        makeMove(&temp, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&temp + 5 + 6 * !temp.whiteToMove));
        if(!isSquareAttacked(&temp, kingPos)){
            eval = -search(&temp, 5);
            bestEval = eval > bestEval ? eval : bestEval;
            bestMove = eval == bestEval ? moves[i] : bestMove;
        }

    }

    return bestMove;

}


int_fast32_t search(BitBoard *board, int depth){

    int_fast32_t result = INT_FAST32_MIN;

    uint8_t kingPos = __builtin_ctzll(*((uint64_t*)board + 5 + 6 * !board->whiteToMove));
    // if the king can be captured this position is invalid we return infinity because capturing the king is the best move always
    if(isSquareAttacked(board, kingPos)){ 
        return INT_FAST32_MAX;
    }

    if(depth == 0){
        return evaluate(board);
    }

    
    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    int_fast32_t eval;
    BitBoard newBoard;

    for(int i = 0; i < numMoves; i++){

        newBoard = *board;
        makeMove(&newBoard, moves[i]);

        eval = -search(&newBoard, depth - 1);

        result = eval > result ? eval : result;
    
    }

    return result;

}