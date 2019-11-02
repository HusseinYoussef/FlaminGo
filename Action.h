#pragma once
#include "definitions.h"
#include "Move.h"

class Action : public Move
{
private:
    /* data */
public:
    Action(Move m);
    Action();
    ~Action();
};
