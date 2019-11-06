/* Represents the Go game state */
#include "definitions.h"
#include "State.h"
#include "Action.h"

State::State(const Board & m) : Board(m)
{
	init();
}

State::State() : Board(BOARD_DIMENSION, std::vector<CellState>(BOARD_DIMENSION, CellState::EMPTY))
{
	std::cout << "state constructed with empty state\n";
}

CapturedStones State::getCapturedstones() const{
	return capturedStones;
}

// State::State(const State& ref){
//   std::cout << "copy const for state\n";
//   std::cout << (*this)[0][11] << '\n';
//   // (*this)[0][0];
//   // std::cout << "copy const for state\n";
//   // for(int i = 0; i< BOARD_DIMENSION; i++){
//   //   for (int j = 0; j<BOARD_DIMENSION; j++){
//   //     (*this)[i][j] = ref[i][j];
//   //   }
//   // }
//   std::cout << "End of copy const for state\n";
// }

State State::operator+(Action m) {
	if (m.isPass()) return (*this);
	State res(*this);
	res(m.p.x, m.p.y) = m.getColour(); // TODO: update with state.nextPlayerToPlay
									   // res.nextPlayerToPlay = m.getColour() == BLACK ? WHITE : BLACK;
	return res;
}

State& State::operator+=(const Action& m) {
	if (m.isPass()) return (*this);
	(*this)(m.p.x, m.p.y) = m.getColour();
	// this->nextPlayerToPlay = m.getColour() == BLACK ? WHITE : BLACK;
	return *this;
}

State& State::operator-=(const Action& m) {
	if (m.isPass()) return (*this);
	(*this)(m.p.x, m.p.y) = EMPTY;
	// this->nextPlayerToPlay = m.getColour() == BLACK ? WHITE : BLACK;
	return *this;
}


CellState& State::operator() (int row, int col)
{
	if (row >= BOARD_DIMENSION || col >= BOARD_DIMENSION || row < 0 || col < 0)
		assert("State subscript out of bounds"); // linux
																		// (*this)[col][row] = EMPTY;
	return (*this)[row][col];
}

CellState State::operator() (int row, int col) const
{
	if (row >= BOARD_DIMENSION || col >= BOARD_DIMENSION || row < 0 || col < 0)
		assert("State subscript out of bounds"); // linux
	return (*this)[row][col];
}

void State::init() {
	this->capturedStones.white = 0;
	this->capturedStones.black = 0;
}

void State::apply_action(Action action)             // apply certain action to this state.
{
	*this += action;
}

State::~State() {}
