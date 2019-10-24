/* 
Represents the player move
*/
#ifndef MOVE_HEADER
#define MOVE_HEADER

class Move
{
private:
    int x, y;
public:
    // construct with point played
    Move(int x, int y);
    bool set_Move(int x,int y);
    // construct with pass move
    Move();

    bool isPass();
    ~Move();
};


#endif
