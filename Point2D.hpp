#pragma once

#include <iostream>

class Point2D
{
public:
	int x = 0;
	int y = 0;

	Point2D(int x = 0, int y = 0) : x{x}, y{y}
	{}

	friend Point2D operator+(const Point2D &p1, const Point2D &p2);
	friend bool operator==(const Point2D &p1, const Point2D &p2);
	friend bool operator!=(const Point2D &p1, const Point2D &p2);
	friend bool operator<(const Point2D &p1, const Point2D &p2);
	friend bool operator>(const Point2D &p1, const Point2D &p2);
	friend bool operator<=(const Point2D &p1, const Point2D &p2);
	friend bool operator>=(const Point2D &p1, const Point2D &p2);

	Point2D& operator+=(const Point2D &p1);
	Point2D operator-();

	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
};
