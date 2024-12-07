#pragma once
#include <string>
#include <sqlite3.h>

/// <summary>
/// Class that manages the game statistics by interacting with a SQLite database.
/// </summary>
class Statistic {
public:

	/// <summary>
	/// Constructor that initializes the Statistic object with the provided database name.
	/// </summary>
	/// <param name="db_name">The name of the SQLite database to store the statistic.</param>
	Statistic(const std::string& db_name);

	/// <summary>
	/// Destructor that releases resources and closes the database connection.
	/// </summary>
	~Statistic();

	/// <summary>
	/// Adds a result to the statistics database.
	/// </summary>
	/// <param name="result">The result to add to the database, win X, win O or draw.</param>
	void AddResult(const std::string& result);

	/// <summary>
	/// Displays the current statistics from database.
	/// </summary>
	void displayStat() const;

private:

	/// <summary>
	/// Initializes and opens the SQLite database connection.
	/// </summary>
	void DB();

	/// <summary>
	/// The name of the SQLite database used to store the statistics.
	/// </summary>
	std::string db_name_;
};