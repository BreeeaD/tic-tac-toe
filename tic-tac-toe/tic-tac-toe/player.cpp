#include "player.hpp"

Player::Player(Cell mark) :mark(mark){}

Cell Player::GetMark() const {
	return mark;//returneaza valoarea simboluilui jucatorului(X sau O)
}