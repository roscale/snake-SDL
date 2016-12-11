#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"
#include <vector>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int BLOCK_SIZE;

class Food;

class Snake
{
private:
	Point2D m_position{1, 1};
	std::vector<Point2D> m_tail = { m_position };
	int m_length = 1;
	Point2D m_direction{1, 0};

public:
	Snake() {};
	Point2D getPosition() const;

	Snake& operator++();

	void up();
	void down();
	void left();
	void right();

	bool checkBiten();
	bool checkFoodEaten(Food *food);

	void update();
	void draw(SDL_Renderer* renderer) const;

	friend class Grid;
};
