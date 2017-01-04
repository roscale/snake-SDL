#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "Point2D.hpp"
#include "Timer.hpp"

class Food;

class Snake
{
public:
	enum class Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	Point2D m_position{1, 1};
	Direction m_direction = Direction::RIGHT;

	std::vector<Direction> input_cache;
	static const std::map<Direction, Point2D> s_directionVectors;
	static const int max_input_cache_size = 2;

	std::vector<Point2D> m_tail = { m_position };
	int m_length = 1;

	Timer m_timer;
	int m_delay = 300;

	Food *p_food = nullptr;

public:
	Snake(Food *food);

	const Point2D& getPosition() const;

	void turn(Direction newDir);

	bool checkBitten();
	bool containsPoint(Point2D point);

	void speedUp();
	void update();
	void push();
	void draw(SDL_Renderer* renderer) const;

	Snake& operator++();

	friend class Game;
	friend class Grid;
};
