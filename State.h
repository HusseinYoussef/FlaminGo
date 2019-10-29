#include "definitions.h"
#include"Move.h"

class State : public Matrix
{
private:
    /* data */
    std::pair<int,int> capturedStones;
public:
    State(const Matrix & m,int capturedByBlack,int capturedByWhite);
    State();
    ~State();
};