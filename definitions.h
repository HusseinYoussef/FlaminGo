#ifndef DEFINITIONS_HEADER_
#define DEFINITIONS_HEADER_

#include<vector>
#include <utility>

#define BOARD_DIMENSION 13
#define KOMI_VALUE 6.5

// core declarations
struct WhiteBlack{
    int white, black;
    WhiteBlack(int white, int black): white(white), black(black)
    {}
    WhiteBlack(): white(0), black(0)
    {}
};

enum CellState {
    EMPTY = 0,
    WHITE = 1,
    BLACK = -1,
};

struct Score : public WhiteBlack
{
    Score(int whiteScore, int blackScore) : WhiteBlack(whiteScore+KOMI_VALUE, blackScore) {}
};


// helper abbreviations
typedef std::pair<int, int> pii;

// new types in terms of other types
typedef std::vector< std::vector<CellState> > Board;
typedef std::vector< std::vector<bool> > Matrix;
typedef WhiteBlack CapturedStones;

#endif