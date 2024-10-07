#include <stdint.h>
#include "BitBoard.h"
#include "Search.h"
#include "Evaluate.h"
#include "MoveGenerator.h"



int32_t quiescenceSearch(BitBoard *board, int32_t alpha, int32_t beta, uint64_t *numNodes){

    (*numNodes) ++;

    int32_t eval = evaluate(board);

    if(eval >= beta) return beta;

    if(eval > alpha) alpha = eval;

    Move moves[218];

    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves); // might need to make a generate captures function
    int possibleMoves = 0;
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
            possibleMoves ++;
        }

    }

    return possibleMoves ? alpha : NEG_INFINITY + 1;

}

int32_t search(BitBoard *board, int depth, int32_t alpha, int32_t beta, uint64_t *numNodes){


    if(depth == 0) return quiescenceSearch(board, alpha, beta, numNodes);

    (*numNodes) ++;


    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    int possibleMoves = 0;
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
            possibleMoves ++;
        }
    
    }

    

    return possibleMoves ? alpha : NEG_INFINITY + 1;

}



Move bestMove(BitBoard board, int depth, uint64_t *numNodes){

    (*numNodes) ++;

    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    uint8_t kingPos;
    BitBoard tempBoard;
    int32_t eval, alpha = NEG_INFINITY;

    Move bestMove = 0; // technically this is meaningless if there are no moves but if there are no moves why are you calling this function

    for(int i = 0; i < numMoves; i++){

        tempBoard = board;
        makeMove(&tempBoard, moves[i]);

        kingPos = __builtin_ctzll(*((uint64_t*)&tempBoard + 5 + 6 * !tempBoard.whiteToMove));
        if(!isSquareAttacked(&tempBoard, kingPos)){
            eval = -search(&tempBoard, depth - 1, NEG_INFINITY, -alpha, numNodes);
            
            if(eval >= POS_INFINITY) return bestMove;

            if(eval > alpha){
                alpha = eval;
                bestMove = moves[i];
            }

        }

    }

    return bestMove;

}



