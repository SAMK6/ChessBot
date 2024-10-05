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
    int_fast32_t eval, bestEval = NEG_INFINITY;

    Move bestMove = 0;

    for(int i = 0; i < numMoves; i++){

        temp = board;
        makeMove(&temp, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&temp + 5 + 6 * !temp.whiteToMove));
        if(!isSquareAttacked(&temp, kingPos)){
            eval = -search(&temp, 6, NEG_INFINITY, POS_INFINITY);
            bestEval = (eval > bestEval) ? eval : bestEval;
            bestMove = (eval == bestEval) ? moves[i] : bestMove;
        }

    }

    return bestMove;

}


int_fast32_t search(BitBoard *board, int depth, int_fast32_t alpha, int_fast32_t beta){


    if(depth == 0) return evaluate(board);

    
    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    int_fast32_t eval;
    uint8_t kingPos;
    BitBoard newBoard;

    for(int i = 0; i < numMoves; i++){

        newBoard = *board;
        makeMove(&newBoard, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&newBoard + 5 + 6 * !newBoard.whiteToMove));

        if(isSquareAttacked(&newBoard, kingPos)) continue;


        eval = -search(&newBoard, depth - 1, -beta, -alpha);

        if(eval >= beta) return beta;

        alpha = eval > alpha ? eval : alpha;
    
    }

    return alpha;

}