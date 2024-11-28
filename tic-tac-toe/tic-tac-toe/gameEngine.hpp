#pragma once
#include "player.hpp"
#include "board.hpp"
#include "..\tic-tac-toe\statistic.hpp"

class GameEngine {
	Board board; //tabla de joc 
	Player player1; //player1
	Player player2; //player2
	Player curent; //playerul care merge la momentul dat
	Statistic stat;

public: 
	GameEngine(Player player1, Player player2);
	void Start(); //incepe jocul
	void SwitchPlayer(); //schimabrea playerului
	void YourTurn(); //gestioneaza o mutare
	void GameOver(); //verifica daca jocul este terminat
};