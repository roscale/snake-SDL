#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"
#include "Grid.hpp"
#include "Snake.hpp"

class Food
{
private:
	Point2D m_position;

	Grid *m_grid = nullptr;
	Snake *m_snake = nullptr;

	void addGrid(Grid *grid);
	void addSnake(Snake *snake);

public:
	Food() {}
	void generate();

	Point2D getPosition() const;

	void draw(SDL_Renderer* renderer) const;

	friend void Grid::addFood(Food *food);
	friend void Snake::addFood(Food *food);
};
