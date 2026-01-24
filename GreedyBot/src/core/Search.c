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
    float bestScore = eval;

    if(bestScore >= beta) return bestScore;
    if(bestScore > alpha) alpha = bestScore;

    Move moves[218];

    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves); // might need to make a generate captures function
    uint8_t kingPos;
    BitBoard tempBoard;

    for(int i = 0; i < numMoves; i++){

        if(!(moves[i] & isCaptureMask)) continue; // only consider capture moves

        tempBoard = *board;
        makeMove(&tempBoard, moves[i]);

        kingPos = *(&tempBoard.blackKingPos + !tempBoard.whiteToMove);
        if(!isSquareAttacked(&tempBoard, kingPos)){

            eval = -quiescenceSearch(&tempBoard, -beta, -alpha, numNodes);

            if(eval >= beta) return eval;
            if(eval > bestScore) bestScore = eval;
            if(eval > alpha) alpha = eval;

        }
    }

    return bestScore;

}

float search(BitBoard *board, int depth, float alpha, float beta, uint64_t *numNodes){


    if(depth == 0) return evaluate(board);

    (*numNodes) ++;


    Move moves[218];
    int numMoves = board->whiteToMove ? generateMovesWhite(board, moves) : generateMovesBlack(board, moves);
    float eval, bestScore = -INFINITY;
    uint8_t kingPos;
    BitBoard tempBoard;

    // printf("%d\n", numMoves);


    for(int i = 0; i < numMoves; i++){

        tempBoard = *board;
        makeMove(&tempBoard, moves[i]);

        kingPos = *(&tempBoard.blackKingPos + !tempBoard.whiteToMove);
        if(!isSquareAttacked(&tempBoard, kingPos)){

            eval = -search(&tempBoard, depth - 1, -beta, -alpha, numNodes);

            if(eval >= bestScore){
                bestScore = eval;
                if(eval > alpha) alpha = eval;
            }
            
            if(eval >= beta) return bestScore;

        }
    
    }

    // printf("%d\n\n", possibleMoves);


    return bestScore;

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



