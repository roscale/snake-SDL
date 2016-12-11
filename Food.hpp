#pragma once

#include <SDL2/SDL.h>
#include "Point2D.hpp"

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int BLOCK_SIZE;

class Food
{
private:
	Point2D m_position;

public:
	Food() { generate(); }

	void generate();
	void draw(SDL_Renderer* renderer) const;

	Point2D getPosition() const;
};
