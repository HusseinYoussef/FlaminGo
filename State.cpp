/*
Represents the Go game state
*/
#include "State.h"

State::State(const Matrix & m,int capturedByBlack,int capturedByWhite): Matrix(m)
{
    this ->capturedStones.first=capturedByBlack;
    this ->capturedStones.second=capturedByWhite;
}
State::State(){
    this ->capturedStones.first=0;
    this ->capturedStones.second=0;
    
}


State::~State()
{
}
