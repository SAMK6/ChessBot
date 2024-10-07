#include <stdint.h>
#include "BitBoard.h"
#include "Search.h"
#include "Evaluate.h"
#include "MoveGenerator.h"



int32_t quiescenceSearch(BitBoard *board, int32_t alpha, int32_t beta, int *numNodes){

    (*numNodes) ++;

    int32_t eval = evaluate(board);

    if(eval >= beta) return beta;

    if(eval > alpha) alpha = eval;

    Move moves[218];

    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves); // might need to make a generate captures function
    uint8_t kingPos;
    BitBoard newBoard;

    for(int i = 0; i < numMoves; i++){

        if(!(moves[i] & isCaptureMask)) continue; // only consider capture moves

        newBoard = *board;
        makeMove(&newBoard, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&newBoard + 5 + 6 * !newBoard.whiteToMove));
        if(!isSquareAttacked(&newBoard, kingPos)){
            eval = -quiescenceSearch(&newBoard, -beta, -alpha, numNodes);
            if(eval >= beta) return beta;
            alpha = eval > alpha ? eval : alpha;
        }

    }

    return alpha;

}

int32_t search(BitBoard *board, int depth, int32_t alpha, int32_t beta, int *numNodes){


    if(depth == 0) return quiescenceSearch(board, alpha, beta, numNodes);

    (*numNodes) ++;
    
    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    int32_t eval;
    uint8_t kingPos;
    BitBoard newBoard;

    for(int i = 0; i < numMoves; i++){

        newBoard = *board;
        makeMove(&newBoard, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&newBoard + 5 + 6 * !newBoard.whiteToMove));
        if(!isSquareAttacked(&newBoard, kingPos)){
            eval = -search(&newBoard, depth - 1, -beta, -alpha, numNodes);
            if(eval >= beta) return beta;
            alpha = eval > alpha ? eval : alpha;
        }
    
    }

    return alpha;

}



Move bestMove(BitBoard board, int *numNodes){

    (*numNodes) ++;

    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    uint8_t kingPos;
    BitBoard temp;
    int32_t eval, bestEval = NEG_INFINITY;

    Move bestMove = 0;

    for(int i = 0; i < numMoves; i++){

        temp = board;
        makeMove(&temp, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&temp + 5 + 6 * !temp.whiteToMove));
        if(!isSquareAttacked(&temp, kingPos)){
            eval = -search(&temp, 7, NEG_INFINITY, POS_INFINITY, numNodes);
            bestEval = (eval > bestEval) ? eval : bestEval;
            bestMove = (eval == bestEval) ? moves[i] : bestMove;
        }

    }

    return bestMove;

}



