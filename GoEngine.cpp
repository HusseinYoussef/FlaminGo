#include "GoEngine.h"

GoEngine::GoEngine()
{
}

bool GoEngine::isValidMove(State state, Move move) {

}


std::vector<Move> GoEngine::getValidMoves(State state,COLOUR nextColourToPlay) {
    std::vector<Move> validMoves;
    Move currentMove;
    for(int i=0;i<MATRIX_DIMENSION;i++){
        for(int j=0;j<MATRIX_DIMENSION;j++){
            currentMove.set_Move(i,j);
            if(isValidMove(state,currentMove))
                validMoves.push_back(currentMove);
        }
    }
    return validMoves;
}

Score GoEngine::computeScore(State state) {

}


GoEngine::~GoEngine()
{
}
