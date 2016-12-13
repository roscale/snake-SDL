#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"
#include <vector>

class Food;

class Snake
{
private:
	Point2D m_position{1, 1};
	Point2D m_direction{1, 0};

	std::vector<Point2D> m_tail = { m_position };
	int m_length = 1;

	Food *p_food = nullptr;

public:
	Snake(Food *food);

	const Point2D& getPosition() const;

	void up();
	void down();
	void left();
	void right();

	bool checkBitten();
	bool checkFoodEaten();
	bool containsBlock(Point2D block);

	void update();
	void draw(SDL_Renderer* renderer) const;

	Snake& operator++();

	friend class Game;
	friend class Grid;
};
