#include "definitions.h"
#include "State.h"
#include "Move.h"
#include<stack>
class GoEngine
{
private:
    
public:
    GoEngine();

    // for given move on state, return true if not legal nor suicidal
    bool isValidMove(State state, Move move);
    std::vector<Move> getValidMoves(State state,COLOUR nextColourToPlay );
    Score computeScore(State state);
    int checkTerritory(int x,int y);
    ~GoEngine();
};