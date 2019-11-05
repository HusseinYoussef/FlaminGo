#pragma once
#include "definitions.h"
#include "Move.h"
#include "Action.h"
class State : public Board
{
private:
    /* data */
    void init();
    CapturedStones capturedStones;
    Player player;  // The player who made the move to this state.
public:
    State(const Board & m, int capturedByBlack,int capturedByWhite);
    State(const Board & m);
    State();
    // State(const State& ref);
    CellState& operator() (int row, int col);
    CellState operator() (int row, int col) const;
    void setCapturedStones(int white, int black);
    State operator+(Move m);
    // H&H
    //bool is_terminal() const;                     // check if this state is terminal state or not. (e.g. end of the game).
    bool get_random_action(Action&);        // return false if no action found.
    result evalute();                       // return if WIN or LOSE - with respect to the AI.
    //void get_actions(vector<Action>&);      // Add all possible actions to the passed vector.         // CHANGED TO GAME ENGINE.
    void apply_action(Action);              // apply certain action to this state.
    Player get_player() const { return player; }

    ~State();
};
