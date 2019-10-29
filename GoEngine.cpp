#include "GoEngine.h"
#include<iostream>
GoEngine::GoEngine()
{
}
/**
 * This Method takes an input position x,y and returns which player has this position and 0 if no one
 * 
 * **/
int checkTerritory(int x,int y,const State &state){
    int currentColorTerritory=0;
    std::stack <std::pair<int,int>> s;
    std::vector<std::vector<bool>> visited(19,std::vector<bool>(19,false)); //creates 19 * 19 vector and gives it an initial value   
    s.push(std::pair(x,y));
    std::pair<int,int> currentPair;
    while(!s.empty()){
        currentPair=s.top();
        s.pop();
        if(!visited[currentPair.first][currentPair.second]){
            if(currentColorTerritory!=0 && currentColorTerritory!=state[currentPair.first][currentPair.second]){
                //not anyone territory
                return 0;
            }
            currentColorTerritory=state[currentPair.first][currentPair.second];
            if(state[currentPair.first][currentPair.second]==0){
                //add it's neighbouring nodes to the stack
                if(currentPair.first==0 && currentPair.second==0){
                    //upper left corner
                    s.push(std::pair(currentPair.first+1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                }
                else if(currentPair.first!=0 && currentPair.second==0){
                    //current pair is at the first row 
                    s.push(std::pair(currentPair.first+1,currentPair.second));
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                }
                else if(currentPair.first==MATRIX_DIMENSION-1 && currentPair.second==0){
                    //upper right corner
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                }
                else if(currentPair.first==0 && currentPair.second==MATRIX_DIMENSION-1){
                    //lower left corner
                    s.push(std::pair(currentPair.first+1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second-1));
                }
                else if (currentPair.first!=0 && currentPair.second==MATRIX_DIMENSION-1){
                    //current pair is at the last row
                    s.push(std::pair(currentPair.first+1,currentPair.second));
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second-1));
                }
                else if(currentPair.first==MATRIX_DIMENSION-1 && currentPair.second==MATRIX_DIMENSION-1){
                    //lower right corner
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second-1));
                }
                else if (currentPair.first==0 && currentPair.second!=0){
                    //first column
                    s.push(std::pair(currentPair.first+1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                    s.push(std::pair(currentPair.first,currentPair.second-1)); 
                }
                else if (currentPair.first==MATRIX_DIMENSION-1 && currentPair.second!=0){
                    //last column
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                    s.push(std::pair(currentPair.first,currentPair.second-1)); 
                }
                else{
                    //current pair is anywhere 
                    s.push(std::pair(currentPair.first-1,currentPair.second));
                    s.push(std::pair(currentPair.first+1,currentPair.second)); 
                    s.push(std::pair(currentPair.first,currentPair.second+1));
                    s.push(std::pair(currentPair.first,currentPair.second-1)); 

                }


            }
        }
    }
    return currentColorTerritory;
}

bool GoEngine::isValidMove(State state, Move move) {
    // occupied point
    /*if (state(pxy(move)) != int(CellState::EMPTY)) return false;
    if (!isOnBoard(move.p)) return false;
    if (move.isPass()) return true;
    
    int numCaptured = updateState_removeCaptures(&state, move);
    if (numCaptured > 0) {
      return isSameState(state);
    }*/

}
bool GoEngine::isKo(State currentState,State prevState){
    for(int i=0;i<MATRIX_DIMENSION;i++){
        for(int j=0;j<MATRIX_DIMENSION;j++){
            if(currentState[i][j]==prevState[i][j])
                return true;
        }
    }
    return false;

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
    int blackStones=0;
    int whiteStones=0;
    int blackTerr=0;
    int whiteTerr=0;
    
    for (int i=0;i<MATRIX_DIMENSION;i++){
        for (int j=0;j<MATRIX_DIMENSION;j++){
            //TODO use the CELL_STATE enum
            if (state[i][j]==-1){
                blackStones++;
            }
            else if(state[i][j]==1){
                whiteStones++;
            }
            else{
                int terr=checkTerritory(i,j);
                if(terr==-1){ blackTerr++;}
                else if(terr==1){whiteTerr++;}
            }
        }
    }
    
}


GoEngine::~GoEngine()
{
}
