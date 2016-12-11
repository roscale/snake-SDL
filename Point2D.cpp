#include "Point2D.hpp"
#include <iostream>

Point2D::Point2D() :
	m_x{0}, m_y{0}
{}

Point2D::Point2D(int x, int y) :
	m_x{x}, m_y{y}
{}

Point2D& Point2D::set(int x, int y)
{
	m_x = x;
	m_y = y;
	return *this;
}
Point2D& Point2D::setX(int value) { m_x = value; return *this;}
Point2D& Point2D::setY(int value) { m_y = value; return *this;}

int Point2D::getX() const { return m_x; }
int Point2D::getY() const { return m_y; }

Point2D operator+(const Point2D &p1, const Point2D &p2)
{ return Point2D(p1.m_x + p2.m_x, p1.m_y + p2.m_y); }

bool operator==(const Point2D &p1, const Point2D &p2) { return (p1.m_x == p2.m_x && p1.m_y == p2.m_y); }
bool operator!=(const Point2D &p1, const Point2D &p2) { return !(p1 == p2); }
bool operator<(const Point2D &p1, const Point2D &p2) { return (p1.m_x < p2.m_x && p1.m_y < p2.m_y); }
bool operator>(const Point2D &p1, const Point2D &p2) { return !(p1 < p2) && (p1 != p2); }
bool operator<=(const Point2D &p1, const Point2D &p2) { return !(p1 > p2); }
bool operator>=(const Point2D &p1, const Point2D &p2) { return !(p1 < p2); }

Point2D& Point2D::operator+=(const Point2D &p1)
{
	m_x += p1.m_x;
	m_y += p1.m_y;
	return *this;
}

Point2D Point2D::operator-() { return Point2D{-m_x, -m_y}; }

std::ostream& operator<<(std::ostream& out, const Point2D& point)
{
	out << "(" << point.m_x << ", " << point.m_y << ")";
	return out;
}
