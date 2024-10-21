#pragma once
#include <iostream>

struct Point
{
	int x;
	int y;


	Point(); //constructor implicit

	Point(int x, int y); //constructor de parametrii

	Point(const Point& other); //construtor de copiere

	Point& operator=(const Point& other); //operator de copiereee

	bool operator == (const Point& other) const; //operator de comparatii

	friend std::istream& operator >> (std::istream& in, Point& p); //operator de citire
	
	friend std::ostream& operator << (std::ostream& out, const Point& p); //opearator de afisare
};