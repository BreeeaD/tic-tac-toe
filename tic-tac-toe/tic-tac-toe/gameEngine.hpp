#pragma once
#include "player.hpp"
#include "board.hpp"
#include "..\tic-tac-toe\statistic.hpp"

/// <summary>
/// Class that handles the game logic for the game.
/// </summary>
class GameEngine {

	/// <summary>
	/// The game board.
	/// </summary>
	Board board;

	/// <summary>
	/// Player 1.
	/// </summary>
	Player player1;

	/// <summary>
	/// Player 2
	/// </summary>
	Player player2;

	/// <summary>
	/// The current player whose turn it is to play.
	/// </summary>
	Player curent;

	/// <summary>
	/// Object that keeps track of the game statistics.
	/// </summary>
	Statistic stat;

public: 

	/// <summary>
	/// Constructor to initialize the game with two players.
	/// </summary>
	/// <param name="player1">Player 1.</param>
	/// <param name="player2">Player 2.</param>
	GameEngine(Player player1, Player player2);

	/// <summary>
	/// Start the game and initializes the necessary components.
	/// </summary>
	void Start();
	
	/// <summary>
	/// Switch current player to the other one.
	/// </summary>
	void SwitchPlayer();
	
	/// <summary>
	/// Manages the player turn, by asking for a move.
	/// </summary>
	void YourTurn();
	
	/// <summary>
	/// Check if the game has ended with a draw or win.
	/// </summary>
	void GameOver();
};