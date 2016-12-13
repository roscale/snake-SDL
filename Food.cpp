#include "Food.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Point2D.hpp"
#include "Grid.hpp"
#include "Snake.hpp"

void Food::addGrid(Grid *grid) { m_grid = grid; }
void Food::addSnake(Snake *snake) { m_snake = snake; }
Point2D Food::getPosition() const { return m_position; }

void Food::generate()
{
	int x, y;
	do
	{
		x = rand() % (m_grid->getWidth());
		y = rand() % (m_grid->getHeight());
		m_position = {x, y};
	} while (m_grid->m_data[x][y] != Grid::BlockType::AIR || m_snake->containsBlock(m_position));
}

void Food::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

	const int &blockSize = m_grid->getBlockSize();
	SDL_Rect blockRect = {
		m_position.x * blockSize,
		m_position.y * blockSize,
		blockSize, blockSize };

	SDL_RenderFillRect(renderer, &blockRect);
}
