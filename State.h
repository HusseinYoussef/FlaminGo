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
    // CellState nextPlayerToPlay; // the color of next player to play, initial state will be white and alternate every time
public:
    CapturedStones getCapturedstones();
    State(const Board & m, int capturedByBlack,int capturedByWhite);
    State(const Board & m);
    State();
    // State(const State& ref);
    CellState& operator() (int row, int col);
    CellState operator() (int row, int col) const;
    State operator+(Move m);
    State& State::operator+=(Move m);
    void setCapturedStones(int white, int black);
    // H&H
    //bool is_terminal() const;                     // check if this state is terminal state or not. (e.g. end of the game).
    Result evalute();                       // return if WIN or LOSE - with respect to the AI.
    //void get_actions(vector<Action>&);      // Add all possible actions to the passed vector.         // CHANGED TO GAME ENGINE.
    void apply_action(Action);              // apply certain action to this state.
    Player get_player() const { return player; }

    ~State();
};
