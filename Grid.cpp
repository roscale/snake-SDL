#include "Grid.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cassert>
#include "Snake.hpp"
#include "Food.hpp"

Grid::Grid(int width, int height) :
	m_width{width}, m_height{height}
{
	assert(width > 0 && height > 0);

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

void Grid::addSnake(Snake *snake) { m_snake = snake; }
void Grid::addFood(Food *food) { m_food = food; }

void Grid::clear()
{
	for (auto &column : m_data)
		for (auto &block : column)
			block = BlockType::AIR;
}

bool Grid::checkCollision()
{
	if (m_snake->checkBiten())
		return true;
	m_snake->checkFoodEaten(m_food);

	if (m_data[m_snake->m_position.getX()][m_snake->m_position.getY()] != BlockType::AIR)
		return true;

	return false;
}

void Grid::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);

	for (int x = 0; x < m_width; x++)
		for (int y = 0; y < m_height; y++)
			switch (m_data[x][y])
			{
				case BlockType::WALL:
					SDL_Rect blockRect = {
						x * BLOCK_SIZE,
						y * BLOCK_SIZE,
						BLOCK_SIZE, BLOCK_SIZE };

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
				case grid.BlockType::AIR:	out << ". "; break;
				case grid.BlockType::WALL:	out << "W "; break;

				default:	out << "U "; break;
			}
		out << '\n';
	}

	return out;
}
