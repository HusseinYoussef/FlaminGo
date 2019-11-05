/* Represents the player move*/
#pragma once
#include "definitions.h"
#include "Action.h"

Action::Action(CellState player, int x, int y) : p(x, y)
{
	this->player = player;
}

Action::Action(CellState color) : p(-1, -1)
{
	this->player = color;
}
Action::Action() {}

bool Action::isPass()
{
	return p.x == -1 && p.y == -1;
}

bool Action::set_Move(int x, int y)
{
	if (x < BOARD_DIMENSION && y < BOARD_DIMENSION)
	{
		this->p.x = x;
		this->p.y = y;
		return true;
	}
	return false;
}
Point Action::getMove()
{
	return this->p;
}
CellState Action::getColour()
{
	return this->player;
}
Action::~Action()
{
}
