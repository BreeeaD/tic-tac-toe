#include "pch.h"
#include "gameEngine.hpp"
#include <iostream>
//#include "E:\sasa\univ\sem3\C++\lab1\tic-tac-toe\tic-tac-toe\tic-tac-toe\statistic.hpp"
#include "..\tic-tac-toe\statistic.hpp"

GameEngine::GameEngine(Player p1, Player p2) :player1(std::move(p1)),player2(std::move(p2)), curent(player1), stat("..\\tic-tac-toe\\database\\game_stats.db") {}//initializarea jucatorilor si jucatorul curent va fi p1



void GameEngine::Start() {
	//while (!board.Full() && !board.CheckWin(player1.GetMark()) && !board.CheckWin(player2.GetMark())) {
		//board.Display(); //afiseaza tabla
		//YourTurn();
		//SwitchPlayer();
	//}
	//GameOver();
	std::cout << "\nStatistica jocurilor:\n";
	stat.displayStat();

	board.Display();
	std::string result;

	while (true) {
		YourTurn();
		board.Display();

		if (board.CheckWin(curent.GetMark())) {
			std::cout << "Player " << (curent.GetMark() == X ? "X" : "O") << " WINS!\n";
			stat.AddResult(curent.GetMark() == X ? "X" : "O"); //
			break;
		}
		else if (board.Full()) {
			std::cout << "EGalitate!\n";
			break;
		}
		SwitchPlayer();
	}
}

void GameEngine::SwitchPlayer() {
	curent = (curent.GetMark() == player1.GetMark()) ? player2 : player1;//schimba jucatorul curent ori lasa acelasi jucator
}

void GameEngine::YourTurn() {
	Point point;
	std::cout << "Player " << (curent.GetMark() == X ? "X" : "O") << " turn. Selectati randul si coloana: ";//cererea de la jucator sa introduca coordonatele
	std::cin >> point.x >> point.y; //citeste coordonatele ale punctului de pe board pe care jucatorul le marcheaza
	if (!board.Mark(point, curent.GetMark())) { //daca coordonata anumita este ocupata atunci il lasa pe jucatorul oarecare sa mai introduca inca odata coordonatele
		std::cout << "Asa miscare nu e permisa. Incearca din nou.\n"; 
		YourTurn();
	}
}

void GameEngine::GameOver() { 
	board.Display(); //afiseaza tabla
	std::string result;

	if (board.CheckWin(player1.GetMark())) { //verifica daca playerul 1 a castigat
		result = "Player X wins";
		std::cout << "Player X e castigatorul!\n";
	}
	else if (board.CheckWin(player2.GetMark())) { //verifica daca playerul 2 a castigat
		result = "Player O wins";
		std::cout << "Player O e castigatorul!\n";
	}
	else {
		result = "Draw";
		std::cout << "Egalitate!\n"; //al treilea caz cand tabla este plina si nu este niciun jucator castigator, egalitate
	}

	stat.AddResult(result);
	std::cout << "\nStatistica jocurilor:\n";
	stat.displayStat();
}