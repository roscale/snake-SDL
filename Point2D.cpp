#include "Point2D.hpp"
#include <iostream>

bool operator==(const Point2D &p1, const Point2D &p2) { return (p1.x == p2.x && p1.y == p2.y); }
bool operator!=(const Point2D &p1, const Point2D &p2) { return !(p1 == p2); }
bool operator<(const Point2D &p1, const Point2D &p2) { return (p1.x < p2.x && p1.y < p2.y); }
bool operator>(const Point2D &p1, const Point2D &p2) { return !(p1 < p2) && (p1 != p2); }
bool operator<=(const Point2D &p1, const Point2D &p2) { return !(p1 > p2); }
bool operator>=(const Point2D &p1, const Point2D &p2) { return !(p1 < p2); }

Point2D operator+(const Point2D &p1, const Point2D &p2) { return Point2D(p1.x + p2.x, p1.y + p2.y); }
Point2D Point2D::operator-() const { return Point2D{-x, -y}; }
Point2D& Point2D::operator+=(const Point2D &p1)
{
	x += p1.x;
	y += p1.y;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Point2D& p1)
{
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}
