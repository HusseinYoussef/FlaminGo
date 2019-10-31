#ifndef GO_ENGINE_H_
#define GO_ENGINE_H_

#include "definitions.h"
#include "State.h"
#include "Move.h"
#include <stack>

typedef std::pair<bool, CellState> Territory;
typedef std::vector<Territory> TerritoryRow;
typedef std::vector<TerritoryRow> TerritoryMat;

class GoEngine
{
private:
    void mergeNewVisited(TerritoryMat& territories, std::stack<Point> &newVisited, CellState territoryColor);
    void buildAllTerritories(const State& state, TerritoryMat& territories);
    CellState getOpponentColor(CellState color);
    bool isValidMove_stateUpdated(State state, const State& prevState, Move move);
    int removeCapturedHelper(State & state,Point point,CellState color);
public:
    GoEngine();

    bool processMove(State& currentState, const State& prevState, Move currentMove); // return the new state in the currentState

    // for given move on state, return true if not legal nor suicidal
    bool isValidMove(State state, const State& prevState, Move move);
    std::vector<Move> getValidMoves(State state,CellState nextColourToPlay );
    Score computeScore(State state);
    void checkTerritory(int x, int y, const State &state, TerritoryMat& territories);
    bool isSelfCapture(const State& state, Point point, CellState color);    
    int removeCaptured(State & state,Point point,CellState color); // take the player stone's color
    bool isKo(const State& currentState,const State& prevState);
    bool isGoal(const State &currentState, Move currentMove, Move prevMove);
    std::vector<Move> getValidMoves(State state,State prevState,CellState nextColourToPlay);
    ~GoEngine();
};


#endif // GO_ENGINE_H_