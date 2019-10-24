#ifndef DEFINITIONS_HEADER_
#define DEFINITIONS_HEADER_

#include<vector>
#include <utility>

// TODO Matrix should be template so that, Matrix in State be "Matrix<CELL_STATE>"
typedef std::vector< std::vector<int> > Matrix;
typedef std::pair<int, int> pii;


struct Score : private pii
{
    Score(int whiteScore, int blackScore) : pii(whiteScore, blackScore){
    }

    int getWhite() { return this->first;}
    int getBlack() { return this->second;}
    
};

enum CELL_STATE {
    EMPTY = 0,
    WHITE = 1,
    BLACK = -1,
}

#endif