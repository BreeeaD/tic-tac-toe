#pragma once
#include "point.hpp"
#include "cell.hpp"
#include <iostream>
#include "abstract_gameEntity.hpp"

class Board : abstract_gameEntity{
	static const int marime = 3; //dimensiunea tablei care dupa reguli este 3x3
	Cell** grid; //reprezentarea tablei printro matrice
public:
	
	Board(); //constructor implicit

	Board(const Board& other); //constructor de parametrii

	~Board(); //destructorul pentru eliberarea memoriei alocata dinamic pentru grid

	Board& operator=(const Board& other); //operator de copiere

	bool operator==(const Board& other) const;//operator de comparatie

	bool Valid(const Point& point) const; //verifica pozitia daca este valida

	void Display() const override; //afiseaseaza tabla
	bool Mark(Point Point, Cell mark); //marceaza pe tabla
	bool Full() const; //verifica daca tabla este plina
	bool CheckWin(Cell mark) const; //verifica daca este un castigator
	Cell ThisCell(Point Point) const; //verifica/primeste starea unei celule

	friend std::istream& operator >> (std::istream& in, Board& board); //operator de citire

	friend std::ostream& operator >> (std::ostream& out, const Board& board); //operator de afisare

private:
	
	bool CheckRowForWin(Cell mark) const; //verifica randurile daca este un castigator
	bool CheckColForWin(Cell mark) const; //verifica coloanele daca este un castigator
	bool CheckDiagForWin(Cell mark) const; //verifica diagonalele daca este un castigator
};