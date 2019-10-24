/* 
Represents the player move
*/
#include "Move.h"

Move::Move(int x, int y)
{
    this->x = x;
    this->y = y;
}

Move::Move()
{
    this->x = -1;
    this->y = -1;
}

bool Move::isPass()
{
    return x == -1  && y == -1;
}

Move::~Move()
{
}
