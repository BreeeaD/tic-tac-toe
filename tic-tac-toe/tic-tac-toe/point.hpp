#pragma once
#include <iostream>

/// <summary>
/// Struct that represents a point in a 2D coordinate system.
/// </summary>
struct Point
{

	/// <summary>
	/// X coordinate 
	/// </summary>
	int x;

	/// <summary>
	/// Y coordinate
	/// </summary>
	int y;

	/// <summary>
	/// Default constructor that initializes th point to (0,0).
	/// </summary>
	Point();

	/// <summary>
	/// Constructor that initializes a point with specific x and y coordinates.
	/// </summary>
	/// <param name="x">x coordinates</param>
	/// <param name="y">y coordinates</param>
	Point(int x, int y);

	/// <summary>
	/// Copy constructor that creates a new point as a copy of another point.
	/// </summary>
	/// <param name="other">The point to copy.</param>
	Point(const Point& other);

	/// <summary>
	/// Assignment operator that copies the state of one point to another.
	/// </summary>
	/// <param name="other">The point whose state is being assigned.</param>
	/// <returns>A refernce to the current point.</returns>
	Point& operator=(const Point& other);

	/// <summary>
	/// Comparison operator to check if two points are equal.
	/// </summary>
	/// <param name="other">The other point to compare.</param>
	/// <returns>True if the two points are the same, otherwise, false.</returns>
	bool operator == (const Point& other) const;

	/// <summary>
	/// Input stream operator to read point data.
	/// </summary>
	/// <param name="in">The input stream from which the point is read.</param>
	/// <param name="p">The point to be updated with the input data.</param>
	/// <returns>The input stream with the updated point.</returns>
	friend std::istream& operator >> (std::istream& in, Point& p);
	
	/// <summary>
	/// Output stream operator to display point data.
	/// </summary>
	/// <param name="out">The output stream where the point data will be displayed.</param>
	/// <param name="p">The point whose data will be printed.</param>
	/// <returns>The output stream with the point data displayed.</returns>
	friend std::ostream& operator << (std::ostream& out, const Point& p);
};