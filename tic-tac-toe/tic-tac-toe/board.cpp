#include "board.hpp"
#include <iostream>

Board::Board() {
	grid = new Cell * [marime];
	for (int i = 0; i < marime; i++) {
		grid[i] = new Cell[marime];
		for (int j = 0; j < marime; j++) {
			grid[i][j] = G; //va initializa toate celulele ca celule libere/goale
		}
	}
}

void Board::Display() const {
	for (int i = 0; i < marime; i++) {
		for (int j = 0; j < marime; j++) {
			char symbol = (grid[i][j] == G) ? '.' : (grid[i][j] == X) ? 'X' : 'O'; //determina simbolul de pe celula, sau daca aceasta este goala
			std::cout << symbol << " "; //afiseaza simbolul pozitiei
		}
		std::cout << std::endl; //va face trecerea la linia urmatoare dupa fiecare rand
	}
}

bool Board::Mark(Point point, Cell mark) {
	if (point.x >= 0 && point.x < marime && point.y >= 0 && point.y < marime && grid[point.x][point.y] == G) { //se verifica conditiile pentru marcarea celulei
		grid[point.x][point.y] = mark; //marceaza pozitia 
		return true; //indica ca marcajul a fost pus
	}
	return false; //indica ca marcajul nu a fost efectuat
}

bool Board::Full() const {
	for (int i = 0; i < marime; i++) {
		for (int j = 0; j < marime; j++) {
			if (grid[i][j] == G) { //face verificarea unei pozitii goale
				return false; //daca gaseste o celula/pozitie goala returneaza imediat false, ceea ce indica ca tabla nu este plina
			}
		}
	}
	return true; //daca nu gaseste nicio celula goala returneaza true
}

bool Board::CheckWin(Cell mark) const {
	return CheckRowForWin(mark) || CheckColForWin(mark) || CheckDiagForWin(mark);//determina daca un jucator a castigat dupa o anumita consitie data
}

Cell Board::ThisCell(Point point) const {
	if (point.x >= 0 && point.x < marime && point.y >= 0 && point.y < marime) { //face verificarea coordonatelor ca acestea sa se afle in limitele tablei
		return grid[point.x][point.y]; //daca pozitia este acea necesara se returneaza valoarea celului de pe pozitia din acest grid
	}
	return G; //daca coordonatele nu sunt corecte se returneaza G
}

bool Board::CheckRowForWin(Cell mark) const {
	for (int i = 0; i < marime; i++) {
		bool win = true;
		for (int j = 0; j < marime; j++) {
			if (grid[i][j] != mark) {
				win = false;//daca gaseste o celula care nu contine mark, atunci seteaza win = false
				break;
			}
		}
		if (win) return true;//daca toate celulele dintrun rand contin mark, atunci metoda indica ca este un castigator
	}
	return false;//daca nu gaseste niciun rand castigator, atunci returneaza false
}

bool Board::CheckColForWin(Cell mark) const {
	for (int i = 0; i < marime; i++) {
		bool win = true;
		for (int j = 0; j < marime; j++) {
			if (grid[j][i] != mark) {
				win = false;//daca gaseste o celula care nu contine mark, atunci seteaza win = false
				break;
			}
		}
		if (win) return true;//daca toate celulele dintro coloana contin mark, atunci metoda indica ca este un castigator
	}
	return false;//daca nu gaseste niciun rand castigator, atunci returneaza false
}

bool Board::CheckDiagForWin(Cell mark) const {
	bool diag1 = true;
	bool diag2 = true;
	for (int i = 0; i < marime; i++) {//parcurge oricare pozitie din diagonale
		if (grid[i][i] != mark) diag1 = false;//daca nicio celula dindiadonala nu contine mark, atunci diag1 este false
		if (grid[i][marime - i - 1] != mark) diag2 = false;//daca nicio celula dindiadonala nu contine mark, atunci diag2 este false
	}
	return diag1 || diag2;
}