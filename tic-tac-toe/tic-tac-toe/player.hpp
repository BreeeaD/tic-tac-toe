#pragma once
#include "board.hpp"

class Player {
public:
	Player(Cell mark); //constructor
	Cell GetMark() const; //obtine locul unde a marcat jucatorul

private:
	Cell mark; //cu ce va marca jucatorul (x sau o)
};