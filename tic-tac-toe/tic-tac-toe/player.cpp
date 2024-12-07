#include "pch.h"
#include "player.hpp"
#include <iostream>

Player::Player() : mark(G){}

Player::Player(Cell mark) : mark(mark){}

bool Player::operator ==(const Player& other) const { 
	return mark == other.mark;
}

Cell Player::GetMark() const {
	return mark;
}

std::istream& operator >> (std::istream& in, Player& player) {  
	int input;
	in >> input;
	player.mark = static_cast<Cell>(input);
	return in;
}

std::ostream& operator << (std::ostream& out, const Player& player) {
	out << (player.mark == X ? "X" : player.mark == O ? "O" : "G");
	return out;
}