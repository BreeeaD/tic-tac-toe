#include "pch.h"
#include "board.hpp"
#include <iostream>
#include <algorithm>

Board::Board() : grid(marime, std::vector<Cell>(marime, G)){}
	
bool Board::operator==(const Board& other) const { 
	return grid == other.grid;
}

void Board::Display() const {
	for (const auto& row:grid) {
		for (const auto& cell : row) {
			char symbol = (cell == G) ? '.' : (cell == X) ? 'X' : 'O';
			std::cout << symbol << " ";
		}
		std::cout << std::endl;
	}
}

bool Board::Mark(Point point, Cell mark) {
	if (Valid(point) && grid[point.x][point.y] == G) { 
		grid[point.x][point.y] = mark; 
		return true; 
	}
	return false; 
}

bool Board::Valid(const Point& point) const {
	return point.x >= 0 && point.x < marime && point.y >= 0 && point.y < marime;
}

bool Board::Full() const {
	return std::all_of(grid.begin(), grid.end(), [](const std::vector<Cell>& row) {
		return std::all_of(row.begin(), row.end(), [](Cell cell) {
			return cell == G;
			});
		});
}

std::istream& operator >> (std::istream& in, Board& board){
	for (auto& row : board.grid) {
		for (auto& cell: row) {
			int val;
			in >> val;
			cell = static_cast<Cell>(val);
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Board& board) {
	for (auto& row : board.grid) {
		for (auto& cell : row) {
			out << (cell == G ? '.' : (cell == X ? 'X' : 'O')) << " ";
		}
		out << std::endl;
	}
	return out;
}

bool Board::CheckWin(Cell mark) const {
	return CheckRowForWin(mark) || CheckColForWin(mark) || CheckDiagForWin(mark);
}

Cell Board::ThisCell(Point point) const {
	if (Valid(point)) {
		return grid[point.x][point.y];
	}
	return G;
}

bool Board::CheckRowForWin(Cell mark) const {
	for (const auto& row : grid) {
		if (std::all_of(row.begin(), row.end(), [mark](Cell cell) {
			return cell == mark;
			}))
		{
			return true;
		}
	}
	return false;
}

bool Board::CheckColForWin(Cell mark) const {
	for (int col = 0; col < marime; col++) {
		if (std::all_of(grid.begin(), grid.end(), [col, mark](const std::vector<Cell>& row) {
			return row[col] == mark;
			})) {
			return true;
		}
	}
	return false;
}

bool Board::CheckDiagForWin(Cell mark) const {
	bool diag1 = std::all_of(grid.begin(), grid.end(), [mark, i = 0](const std::vector<Cell>& row)mutable {
		return row[i++] == mark;
		});
	bool diag2 = std::all_of(grid.begin(), grid.end(), [mark, i = marime - 1](const std::vector<Cell>& row)mutable {
		return row[i--] == mark;
		});
	return diag1 || diag2;
}