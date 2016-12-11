#include "Food.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Point2D.hpp"

void Food::generate()
{
	int x = rand() % (WINDOW_WIDTH / BLOCK_SIZE);
	int y = rand() % (WINDOW_HEIGHT / BLOCK_SIZE);

	m_position.set(x, y);
}

void Food::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

	SDL_Rect blockRect = {
		m_position.getX() * BLOCK_SIZE,
		m_position.getY() * BLOCK_SIZE,
		BLOCK_SIZE, BLOCK_SIZE };

	SDL_RenderFillRect(renderer, &blockRect);
}

Point2D Food::getPosition() const { return m_position; }
