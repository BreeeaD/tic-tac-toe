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
			stat.AddResult(curent.GetMark() == X ? "X" : "O"); 
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
	curent = (curent.GetMark() == player1.GetMark()) ? player2 : player1;
}

void GameEngine::YourTurn() {
	Point point;
	std::cout << "Player " << (curent.GetMark() == X ? "X" : "O") << " turn. Selectati randul si coloana: ";
	std::cin >> point.x >> point.y;
	if (!board.Mark(point, curent.GetMark())) {
		std::cout << "Asa miscare nu e permisa. Incearca din nou.\n"; 
		YourTurn();
	}
}

void GameEngine::GameOver() { 
	board.Display();
	std::string result;

	if (board.CheckWin(player1.GetMark())) {
		result = "Player X wins";
		std::cout << "Player X e castigatorul!\n";
	}
	else if (board.CheckWin(player2.GetMark())) {
		result = "Player O wins";
		std::cout << "Player O e castigatorul!\n";
	}
	else {
		result = "Draw";
		std::cout << "Egalitate!\n";
	}

	stat.AddResult(result);
	std::cout << "\nStatistica jocurilor:\n";
	stat.displayStat();
}