#include "pch.h"
#include "point.hpp"

Point::Point() : x(0), y(0) {} 

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {} 

Point& Point::operator=(const Point& other) { 
	if (this != &other) {
		x = other.x;
		y = other.y;
	}
	return *this;
}

bool Point::operator == (const Point& other) const { 
	return x == other.x && y == other.y;
}

std::istream& operator >> (std::istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

std::ostream& operator << (std::ostream& out, const Point& p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}