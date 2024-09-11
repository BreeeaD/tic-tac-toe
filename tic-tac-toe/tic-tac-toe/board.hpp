#pragma once
#include "point.hpp"
enum Cell{G, X, O}; // enumerarea celulei (anume starea acesteia)

class Board {
public:
	static const int marime = 3; //dimensiunea tablei care dupa reguli este 3x3

	Board(); //constructor
	void Display() const; //afiseaseaza tabla
	bool Mark(Point Point, Cell mark); //marceaza pe tabla
	bool Full() const; //verifica daca tabla este plina
	bool CheckWin(Cell mark) const; //verifica daca este un castigator
	Cell ThisCell(Point Point) const; //verifica/primeste starea unei celule

private:
	Cell** grid; //reprezentarea tablei printro matrice
	bool CheckRowForWin(Cell mark) const; //verifica randurile daca este un castigator
	bool CheckColForWin(Cell mark) const; //verifica coloanele daca este un castigator
	bool CheckDiagForWin(Cell mark) const; //verifica diagonalele daca este un castigator
};