#include "definitions.h"
#include "State.h"
#include "Move.h"

class GoEngine
{
private:
    
public:
    GoEngine();

    // for given move on state, return true if not legal nor suicidal
    bool isValidMove(State state, Move move);
    std::vector<Move> getValidMoves(State state);
    Score computeScore(State state);
    ~GoEngine();
};