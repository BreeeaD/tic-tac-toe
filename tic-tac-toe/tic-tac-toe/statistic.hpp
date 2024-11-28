#pragma once
#include <string>
#include <sqlite3.h>


class Statistic {
public:
	Statistic(const std::string& db_name);
	~Statistic();

	void AddResult(const std::string& result);
	void displayStat() const;

private:
	void DB();
	std::string db_name_;
};