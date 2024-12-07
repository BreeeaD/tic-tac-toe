#pragma once
#include "board.hpp"
#include "cell.hpp"
#include <iostream>
#include "abstract_gameEntity.hpp"

/// <summary>
/// Class representing a player.
/// </summary>
class Player : public abstract_gameEntity{
public:

	/// <summary>
	/// Default constructor that initializes a player with no specific mark;
	/// </summary>
	Player();

	/// <summary>
	/// Constructor that initializes a player with a specific mark.
	/// </summary>
	/// <param name="mark">The specific mark, X or O, for player.</param>
	Player(Cell mark);

	/// <summary>
	/// Copy constructor that creates a new player as a copy of another player.
	/// </summary>
	/// <param name="other">The player to copy.</param>
	Player(const Player& other) = default;

	/// <summary>
	/// Assignment operator to copy the state of one player to another.
	/// </summary>
	/// <param name="other">The player whose state is being assigned.</param>
	/// <returns>A reference to the current player.</returns>
	Player& operator=(const Player& other) = default; 

	/// <summary>
	/// Comparison operator to check if two players are equal based on their mark.
	/// </summary>
	/// <param name="other">The other player to compare.</param>
	/// <returns>True if the players are the same, otherwise, false.</returns>
	bool operator==(const Player& other) const; 

	/// <summary>
	/// Get the mark of the player, X or O.
	/// </summary>
	/// <returns>The mark of tthe player.</returns>
	Cell GetMark() const; 

	/// <summary>
	/// Input stream operator to read player data.
	/// </summary>
	/// <param name="in">The input stream form wich player is read.</param>
	/// <param name="player">The player to be updated with the input data.</param>
	/// <returns>The input stream with the updated player</returns>
	friend std::istream& operator >> (std::istream& in, Player& player); 

	/// <summary>
	/// Output stream operator to display player data.
	/// </summary>
	/// <param name="out">The output stream where the player data will be diplayed.</param>
	/// <param name="player">The player whose data will be printed.</param>
	/// <returns>The output stream with the player data displayed.</returns>
	friend std::ostream& operator << (std::ostream& out, const Player& player); 

	/// <summary>
	/// Displays the player's mark on the console.
	/// </summary>
	void Display() const override {
		std::cout << "Player:" << (mark == X ? 'X' : 'O') << std::endl;
	}

private:
	/// <summary>
	/// The mark that player uses in the game, X or O.
	/// </summary>
	Cell mark;
};