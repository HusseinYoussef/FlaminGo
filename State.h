#include "definitions.h"
#include"Move.h"

class State : public Board
{
private:
    /* data */
    void init();
    CapturedStones capturedStones;
public:
    State(const Board & m, int capturedByBlack,int capturedByWhite);
    State(const Board & m);
    State();
    // State(const State& ref);
    CellState& operator() (int row, int col);
    CellState operator() (int row, int col) const;
    void setCapturedStones(int white, int black);
    State operator+(Move m);
    ~State();
};