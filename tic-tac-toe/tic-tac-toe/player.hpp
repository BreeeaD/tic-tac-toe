#pragma once
#include "board.hpp"

class Player {
public:
	Player(Cell mark); //constructor
	Cell Mark() const; //obtine locul unde a marcat jucatorul

private:
	Cell mark; //cu ce va marca jucatorul (x sau o)
};