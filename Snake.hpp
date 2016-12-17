#pragma once

#include <SDL2/SDL.h>
#include <vector>
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

	Timer m_timer;
	int m_delay = 300;
	bool input_locked = false; // Prevent spam input

private:
	Point2D m_position{1, 1};
	Point2D m_direction{1, 0};

	std::vector<Point2D> m_tail = { m_position };
	int m_length = 1;

	Food *p_food = nullptr;

public:
	Snake(Food *food);

	const Point2D& getPosition() const;

	void turn(Direction newDir);

	bool checkBitten();
	bool containsBlock(Point2D block);
	void speedUp();

	void update();
	void push();
	void draw(SDL_Renderer* renderer) const;

	Snake& operator++();

	friend class Game;
	friend class Grid;
};
