/* 
Represents the player move
*/
#ifndef MOVE_HEADER_H_
#define MOVE_HEADER_H_
#include "Point.h"
#include "definitions.h"

class Move
{
private:
public:
    Point p;
    CellState player;
    
    Move(); // default constructor
    // construct with point played
    Move(CellState player, int x, int y);
    Move(CellState player, Point p);
    Move(CellState player); // pass move
    bool set_Move(int x, int y);
    Point getMove();
    CellState getColour();
    bool isPass();
    ~Move();
};


#endif

