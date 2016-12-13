#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"
#include "Snake.hpp"

class Grid;

class Food
{
private:
	Point2D m_position;

	Grid *p_grid = nullptr;
	Snake *p_snake = nullptr;

	void addGrid(Grid *grid);
	void addSnake(Snake *snake);

public:
	Food(Grid *grid);

	void generate();

	Point2D getPosition() const;

	void draw(SDL_Renderer* renderer) const;

	// friend void Grid::addFood(Food *food);
	friend Snake::Snake(Grid *grid, Food *food);
};
