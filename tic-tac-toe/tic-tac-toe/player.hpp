#pragma once
#include "board.hpp"
#include "cell.hpp"
#include <iostream>
#include "abstract_gameEntity.hpp"

class Player : public abstract_gameEntity{
public:

	Player(); //constructor implicit

	Player(Cell mark); //constructor de parametrii

	Player(const Player& other) = default; //constructor de copiere

	Player& operator=(const Player& other) = default; //operator de copiere

	bool operator==(const Player& other) const; //operator de comparatie

	Cell GetMark() const; //obtine locul unde a marcat jucatorul

	friend std::istream& operator >> (std::istream& in, Player& player); //operator de citire 

	friend std::ostream& operator << (std::ostream& out, const Player& player); //operator de afisare

	void Display() const override {
		std::cout << "Player:" << (mark == X ? 'X' : 'O') << std::endl;
	}

private:
	Cell mark;
};