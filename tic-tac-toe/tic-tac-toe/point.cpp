#include "point.hpp"

Point::Point() : x(0), y(0) {} //constructor implicit

Point::Point(int x, int y) : x(x), y(y) {} //constructor de parametrii

Point::Point(const Point& other) : x(other.x), y(other.y) {} //constructor de copiere

Point& Point::operator=(const Point& other) { //operator de copiereee
	if (this != &other) {
		x = other.x;
		y = other.y;
	}
	return *this;
}

bool Point::operator == (const Point& other) const { //operator de comparatie
	return x == other.x && y == other.y;
}

std::istream& operator >> (std::istream& in, Point& p) { //operator de citire
	in >> p.x >> p.y;
	return in;
}

std::ostream& operator << (std::ostream& out, const Point& p) { //opearator de afisare
	out << "(" << p.x << "," << p.y << ")";
	return out;
}