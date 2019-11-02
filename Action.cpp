/*
- Action is a move plus some agent parameters like (action prob, action cost, action heuristics, ...).
- if you are talking about gameEngine, it just understands the move,
  the agent take this move and convert it to action with some additional features.
- for now, the action is just a move
*/
#pragma once
#include "definitions.h"
#include "Action.h"
#include "Move.h"

Action::Action(Move m) : Move(m)
{
}

Action::Action() {}

Action::~Action()
{
}
