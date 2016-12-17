#include "Grid.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cassert>
#include "Snake.hpp"
#include "Food.hpp"

Grid::Grid()//int width, int height, int blockSize) :
	//WIDTH{width}, HEIGHT{height}, BLOCK_SIZE{blockSize}
{
	assert(Grid::WIDTH > 0 && Grid::HEIGHT > 0);

	// Reserve matrix
	m_data.resize(Grid::WIDTH);
	for (auto &v : m_data)
		v.resize(Grid::HEIGHT);
	clear();

	// Create walls
	for (int w = 0; w < Grid::WIDTH; w++)
		m_data[w][0] = BlockType::WALL;

	for (int h = 0; h < Grid::HEIGHT; h++)
		m_data[0][h] = BlockType::WALL;

	for (int w = Grid::WIDTH-1; w >= 0; w--)
		m_data[w][Grid::HEIGHT-1] = BlockType::WALL;

	for (int h = Grid::HEIGHT-1; h >= 0; h--)
		m_data[Grid::WIDTH-1][h] = BlockType::WALL;

	// Trolling is good
	// for (int i = 0; i < Grid::WIDTH; i+=2)
	// {
	// 	m_data[i][i] = BlockType::WALL;
	// 	m_data[i][Grid::HEIGHT - i] = BlockType::WALL;
	// }

	//m_data[Grid::WIDTH/2][Grid::HEIGHT/2] = BlockType::WALL;
}

Grid::BlockType Grid::at(int x, int y) { return m_data[x][y]; }

void Grid::clear()
{
	for (auto &column : m_data)
		for (auto &block : column)
			block = BlockType::AIR;
}

void Grid::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);

	for (int x = 0; x < Grid::WIDTH; x++)
		for (int y = 0; y < Grid::HEIGHT; y++)
			switch (m_data[x][y])
			{
				case BlockType::WALL:
					SDL_Rect blockRect = {
						x * Grid::BLOCK_SIZE,
						y * Grid::BLOCK_SIZE,
						Grid::BLOCK_SIZE, Grid::BLOCK_SIZE };

					SDL_RenderFillRect(renderer, &blockRect);
					break;
			}
}

std::ostream& operator<<(std::ostream &out, const Grid &grid)
{
	for (int y = 0; y < Grid::HEIGHT; y++)
	{
		for (int x = 0; x < Grid::WIDTH; x++)
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
