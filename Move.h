/* 
Represents the player move
*/
#ifndef MOVE_HEADER
#define MOVE_HEADER

#include"definitions.h"
class Move
{
private:
    int x, y;
    COLOUR moveColour;

public:
    // construct with point played
    Move(int x, int y);
    bool set_Move(int x,int y);
    // construct with pass move
    Move();
    std::pair<int,int> getMove();
    COLOUR getColour();
    bool isPass();
    ~Move();
};


#endif
