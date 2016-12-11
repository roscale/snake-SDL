#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int BLOCK_SIZE;

class Grid;
class Snake;

class Food
{
private:
	Point2D m_position;

	Grid *m_grid = nullptr;
	Snake *m_snake = nullptr;

	
public:
	Food() { }//generate(); }

	Point2D generate();
	void draw(SDL_Renderer* renderer) const;

	Point2D getPosition() const;
};
