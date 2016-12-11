#pragma once

#include <iostream>

class Point2D
{
private:
	int m_x;
	int m_y;

public:
	Point2D();
	Point2D(int x, int y);

	Point2D& set(int x, int y);
	Point2D& setX(int value);
	Point2D& setY(int value);

	int getX() const;
	int getY() const;

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
