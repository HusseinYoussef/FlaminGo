/* 
Represents the player move
*/
#include "Move.h"
#include "definitions.h"

Move::Move(CellState player, int x, int y) : p(x, y)
{
    this->player = player;
}

Move::Move(CellState color) : p(-1, -1)
{
    this->player = color;
}

bool Move::isPass()
{
    return p.x == -1 && p.y == -1;
}

bool Move::set_Move(int x, int y)
{
    if (x < BOARD_DIMENSION && y < BOARD_DIMENSION)
    {
        this->p.x = x;
        this->p.y = y;
        return true;
    }
    return false;
}
Point Move::getMove()
{
    return this->p;
}
CellState Move::getColour()
{
    return this->player;
}
Move::~Move()
{
}
