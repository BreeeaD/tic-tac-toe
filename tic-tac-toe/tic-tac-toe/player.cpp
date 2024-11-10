#include "player.hpp"
#include <iostream>

Player::Player() : mark(G){} //constructor implicit

Player::Player(Cell mark) : mark(mark){} //constructor de parametrii

bool Player::operator ==(const Player& other) const { //operator de comparatie
	return mark == other.mark;
}

Cell Player::GetMark() const {
	return mark;//returneaza valoarea simboluilui jucatorului(X sau O)
}

std::istream& operator >> (std::istream& in, Player& player) { //operator de citire 
	int input;
	in >> input;
	player.mark = static_cast<Cell>(input);
	return in;
}

std::ostream& operator << (std::ostream& out, const Player& player) { //operator de afisare
	out << (player.mark == X ? "X" : player.mark == O ? "O" : "G");
	return out;
}