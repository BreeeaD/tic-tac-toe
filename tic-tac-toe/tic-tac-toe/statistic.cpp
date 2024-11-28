#include"statistic.hpp"
#include <iostream>
#include <sqlite3.h>
#include <filesystem>
//#include <nlohmann/json.hpp>

Statistic::Statistic(const std::string& db_name) :db_name_(db_name) {
	std::cout << "Baza de date va fi creata/salvata la: " << std::filesystem::absolute(db_name_) << "\n";
	std::filesystem::create_directories("database");
	DB();
}

Statistic::~Statistic(){}

void Statistic::DB() {
	sqlite3* db;
	if (sqlite3_open(db_name_.c_str(), &db) == SQLITE_OK) {
		const char* create_table =
			"CREATE TABLE IF NOT EXISTS GameStats ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"result TEXT NOT NULL);";
		sqlite3_exec(db, create_table, nullptr, nullptr, nullptr);
		sqlite3_close(db);
	}
}

void Statistic::AddResult(const std::string& result) {
	sqlite3* db;
	if (sqlite3_open(db_name_.c_str(), &db) == SQLITE_OK) {
		std::string sql = "INSERT INTO GameStats (result) VALUES ('" + result + "');";
		char* error_m = nullptr;
		int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_m);
		if (rc != SQLITE_OK) {
			std::cout << "eroare:" << error_m << std::endl;
			sqlite3_free(error_m);
		}
		else {
			std::cout << "Rezultat salvat: " << result << "\n";
		}
		sqlite3_close(db);
	}
	else {
		std::cout << "nu se dischide DB: " << sqlite3_errmsg << std::endl;
	}
}

void Statistic::displayStat() const {
	sqlite3* db;
	if (sqlite3_open(db_name_.c_str(), &db) == SQLITE_OK) {
		const char* query = "SELECT result, COUNT(*) FROM GameStats GROUP BY result;";
		sqlite3_stmt* stmt;
		if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
			bool found = false;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				found = true;
				std::string result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
				int count = sqlite3_column_int(stmt, 1);
				std::cout << result << ": " << count << "jocuri\n";
			}
			if (!found) {
				std::cout << "Nu exista statistica.\n";
			}
			sqlite3_finalize(stmt);
		}
		else
		{
			std::cout << "erroare aici in display: " << sqlite3_errmsg(db) << std::endl;
		}
		sqlite3_close(db);
	}
	else
	{
		std::cout << "erroare in accesarea DB: " << sqlite3_errmsg(db) << std::endl;
	}
}