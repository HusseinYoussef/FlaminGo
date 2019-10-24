/*
- Action is a move plus some agent parameters like (action prob, action cost, action heuristics, ...).
- if you are talking about gameEngine, it just understands the move,
  the agent take this move and convert it to action with some additional features.
- for now, the action is just a move
*/
#include "Action.h"

Action::Action(Move m) : Move(m)
{
}

Action::~Action()
{
}
