#include "Grid.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cassert>
#include "Snake.hpp"
#include "Food.hpp"

Grid::Grid(int width, int height, int blockSize) :
	m_width{width}, m_height{height}, m_blockSize{blockSize}
{
	assert(width > 0 && height > 0);

	// Reserve matrix
	m_data.resize(width);
	for (auto &v : m_data)
		v.resize(height);
	clear();

	// Create walls
	for (int w = 0; w < width; w++)
		m_data[w][0] = BlockType::WALL;

	for (int h = 0; h < height; h++)
		m_data[0][h] = BlockType::WALL;

	for (int w = width-1; w >= 0; w--)
		m_data[w][height-1] = BlockType::WALL;

	for (int h = height-1; h >= 0; h--)
		m_data[width-1][h] = BlockType::WALL;

	// Trolling is good
	m_data[width/2][height/2] = BlockType::WALL;
}

void Grid::addSnake(Snake *snake)
{
	m_snake = snake;
	snake->addGrid(this);
}
void Grid::addFood(Food *food)
{
	m_food = food;
	food->addGrid(this);
}

Grid::BlockType Grid::at(int x, int y) { return m_data[x][y]; }
int Grid::getWidth() const { return m_width; };
int Grid::getHeight() const { return m_height; };
int Grid::getBlockSize() const { return m_blockSize; };

void Grid::clear()
{
	for (auto &column : m_data)
		for (auto &block : column)
			block = BlockType::AIR;
}

// bool Grid::checkCollisions()
// {
// 	m_snake->checkFoodEaten();
// 	if (m_snake->checkBitten())
// 		return true;
//
// 	if (m_data[m_snake->m_position.x][m_snake->m_position.y] != BlockType::AIR)
// 		return true;
//
// 	return false;
// }

void Grid::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);

	for (int x = 0; x < m_width; x++)
		for (int y = 0; y < m_height; y++)
			switch (m_data[x][y])
			{
				case BlockType::WALL:
					SDL_Rect blockRect = {
						x * m_blockSize,
						y * m_blockSize,
						m_blockSize, m_blockSize };

					SDL_RenderFillRect(renderer, &blockRect);
					break;
			}
}

std::ostream& operator<<(std::ostream &out, const Grid &grid)
{
	for (int y = 0; y < grid.m_height; y++)
	{
		for (int x = 0; x < grid.m_width; x++)
			switch (grid.m_data[x][y])
			{
				case Grid::BlockType::AIR:		out << ". "; break;
				case Grid::BlockType::WALL:	out << "W "; break;

				default:	out << "U "; break;
			}
		out << '\n';
	}
	return out;
}
