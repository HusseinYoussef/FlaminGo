/* 
Represents the player move
*/
#include "Move.h"
#include"definitions.h"

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

bool Move::set_Move(int x,int y){
    if(x<MATRIX_DIMENSION && y<MATRIX_DIMENSION){
        this ->x=x;
        this ->y=y;
        return true;
    }
    return false;
}
std::pair<int,int> Move:: getMove(){
    return std::pair(x,y);
}
COLOUR Move:: getColour(){
    return this->moveColour;
}


Move::~Move()
{
}
