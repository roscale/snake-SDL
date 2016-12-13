#include "globals.hpp"
#include "Food.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Point2D.hpp"
#include "Grid.hpp"
#include "Snake.hpp"

Food::Food(Grid *grid) : p_grid{grid}
{}

void Food::addGrid(Grid *grid) { p_grid = grid; }
void Food::addSnake(Snake *snake) { p_snake = snake; }

Point2D Food::getPosition() const { return m_position; }

void Food::generate()
{
	int x, y;
	do
	{
		x = rand() % (GRID_WIDTH);
		y = rand() % (GRID_HEIGHT);
		m_position = {x, y};
	} while (p_grid->at(x, y) != Grid::BlockType::AIR || p_snake->containsBlock(m_position));
}

void Food::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

	const int &blockSize = BLOCK_SIZE;
	SDL_Rect blockRect = {
		m_position.x * blockSize,
		m_position.y * blockSize,
		blockSize, blockSize };

	SDL_RenderFillRect(renderer, &blockRect);
}
