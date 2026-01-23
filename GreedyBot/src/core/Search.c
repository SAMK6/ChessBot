#include <stdint.h>
#include <math.h>
#include <stdio.h>

#include "BitBoard.h"
#include "Search.h"
#include "Evaluate.h"
#include "MoveGenerator.h"
#include "Translator.h"



float quiescenceSearch(BitBoard *board, float alpha, float beta, uint64_t *numNodes){

    (*numNodes) ++;

    float eval = evaluate(board);

    if(eval >= beta) return beta;

    if(eval > alpha) alpha = eval;

    Move moves[218];

    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves); // might need to make a generate captures function
    int possibleMoves = 0;
    uint8_t kingPos;
    BitBoard tempBoard;

    for(int i = 0; i < numMoves; i++){

        if(!(moves[i] & isCaptureMask)) continue; // only consider capture moves

        tempBoard = *board;
        makeMove(&tempBoard, moves[i]);

        kingPos = *(&tempBoard.blackKingPos + !tempBoard.whiteToMove);
        if(!isSquareAttacked(&tempBoard, kingPos)){
            eval = -quiescenceSearch(&tempBoard, -beta, -alpha, numNodes);
            if(eval >= beta) return beta;
            alpha = eval > alpha ? eval : alpha;
            possibleMoves ++;
        }
    }

    return possibleMoves ? alpha : evaluate(board);

}

float search(BitBoard *board, int depth, float alpha, float beta, uint64_t *numNodes){


    if(depth == 0) return evaluate(board);

    (*numNodes) ++;


    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    int possibleMoves = 0;
    float eval;
    uint8_t kingPos;
    BitBoard tempBoard;

    // printf("%d\n", numMoves);


    for(int i = 0; i < numMoves; i++){

        tempBoard = *board;
        makeMove(&tempBoard, moves[i]);

        kingPos = *(&tempBoard.blackKingPos + !tempBoard.whiteToMove);
        if(!isSquareAttacked(&tempBoard, kingPos)){
            eval = -search(&tempBoard, depth - 1, -beta, -alpha, numNodes);
            if(eval >= beta) return beta;
            alpha = eval > alpha ? eval : alpha;
            possibleMoves ++;
        }
    
    }

    // printf("%d\n\n", possibleMoves);


    return possibleMoves ? alpha : -INFINITY;

}



Move bestMove(BitBoard board, int depth, uint64_t *numNodes){

    (*numNodes) ++;

    Move moves[218];
    int numMoves = board.whiteToMove ? generateMovesWhite(&board, moves) : generateMovesBlack(&board, moves);

    // printf("%d\n\n", numMoves);

    uint8_t kingPos;
    BitBoard tempBoard;
    float eval, alpha = -INFINITY;

    Move bestMove = 0; // should help with debugging

    for(int i = 0; i < numMoves; i++){

        // new board after making the move
        tempBoard = board;
        makeMove(&tempBoard, moves[i]);

        // char myMove[6];

        // moveToUCI(moves[i], myMove);

        // printf("%s\n", myMove);

        // check if this position is legal
        kingPos = *(&tempBoard.blackKingPos + !tempBoard.whiteToMove);
        if(!isSquareAttacked(&tempBoard, kingPos)){

            // printf("%s\n\n", myMove);

            eval = -search(&tempBoard, depth - 1, -INFINITY, -alpha, numNodes);
                
            if(eval >= INFINITY) return moves[i];

            if(eval > alpha){
                alpha = eval;
                bestMove = moves[i];
            }
        }

    }

    return bestMove;

}



