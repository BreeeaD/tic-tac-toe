/*
Project: Tic-Tac-ToeGame
Author: Trusov Alexandr
Year: 2024
*/

#pragma once
#include "point.hpp"
#include "cell.hpp"
#include <iostream>
#include "abstract_gameEntity.hpp"
#include <vector>
#include <memory>

/// <summary>
/// Represents the game Board.
/// </summary>
class Board : public abstract_gameEntity{
	/// <summary>
	/// Board size 3x3.
	/// </summary>
	static const int marime = 3;
	/// <summary>
	/// Representing the Board through a 2D grid
	/// </summary>
	std::vector<std::vector<Cell>> grid;
public:

	/// <summary>
	/// Constructs a default Board object.
	/// </summary>
	Board();

	/// <summary>
	/// Construct the Board object by copying other instance
	/// </summary>
	/// <param name="other">The Board instance to this one.</param>
	Board(const Board& other) = default;

	/// <summary>
	/// Destroys the board object and releases any dinamically allocated memory.
	/// </summary>
	~Board() = default;

	/// <summary>
	/// Assigns the contents of another board instance to this one.
	/// </summary>
	/// <param name="other">The Board instance to this one.</param>
	/// <returns>A reference to the updated Board instance.</returns>
	Board& operator=(const Board& other) = default;

	/// <summary>
	/// Compares two Board objects for equality based in their grid states.
	/// </summary>
	/// <param name="other">The Board instance to this one.</param>
	/// <returns>True if theboard are identical, otherwise, false.</returns>
	bool operator==(const Board& other) const;

	/// <summary>
	/// Check wether a given point is a valid position on the board.
	/// </summary>
	/// <param name="point">The point to validate.</param>
	/// <returns>True if the point is within the board's bounds, otherwise, false.</returns>
	bool Valid(const Point& point) const;

	/// <summary>
	/// Displays the current states of the board
	/// </summary>
	void Display() const override;

	/// <summary>
	/// Marks a cell on the board with a specified symbol if the cell is unocupied.
	/// </summary>
	/// <param name="Point">The position to mark.</param>
	/// <param name="mark">The mark, X or O, to place in the cell.</param>
	/// <returns>True if the cell was successfully marked, otherwise, flase.</returns>
	bool Mark(Point Point, Cell mark);
	
	/// <summary>
	/// Checks wether the board is completly full.
	/// </summary>
	/// <returns>True if the board is full, otherwise, false</returns>
	bool Full() const;
	
	/// <summary>
	/// CHecks wether a player with the given mark has won the game.
	/// </summary>
	/// <param name="mark">The mark to check for a winning condition.</param>
	/// <returns>True if player has won, otherwise, false</returns>
	bool CheckWin(Cell mark) const; 
	
	/// <summary>
	/// Retrieves the state of a specific cell on the board.
	/// </summary>
	/// <param name="Point">The position of the cell to retrieve.</param>
	/// <returns>The state of the cell, X or O or G.</returns>
	Cell ThisCell(Point Point) const;

	/// <summary>
	/// Reads the board state from an input stream.
	/// </summary>
	/// <param name="in">The input stream.</param>
	/// <param name="board">The Board instance to populate.</param>
	/// <returns>The modified input stream.</returns>
	friend std::istream& operator >> (std::istream& in, Board& board);

	/// <summary>
	/// Outputs the board state to an output stream.
	/// </summary>
	/// <param name="out">The output stream.</param>
	/// <param name="board">The Board instance to display.</param>
	/// <returns>The modified output stream.</returns>
	friend std::ostream& operator << (std::ostream& out, const Board& board);

private:
	
	/// <summary>
	/// Checks all rows for a winning condition for the specified mark.
	/// </summary>
	/// <param name="mark">The mark to check for a winning condition.</param>
	/// <returns>True if a winning condition is found in any row, otherwise, false.</returns>
	bool CheckRowForWin(Cell mark) const;
	
	/// <summary>
	/// Checks all columns for a winning condition for the specified mark.
	/// </summary>
	/// <param name="mark">The mark to check for a winning condition.</param>
	/// <returns>True if a winning condition is found in any columns, otherwise, false.</returns>
	bool CheckColForWin(Cell mark) const;
	
	/// <summary>
	/// Checks all diagonals for a winning condition for the specified mark.
	/// </summary>
	/// <param name="mark">The mark to check for a winning condition.</param>
	/// <returns>True if a winning condition is found in any diagonal, otherwise, false.</returns>
	bool CheckDiagForWin(Cell mark) const;
};