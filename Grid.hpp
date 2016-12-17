#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

class Grid
{
public:
	static const int WIDTH;
	static const int HEIGHT;
	static const int BLOCK_SIZE;

	enum class BlockType
	{
		AIR,
		WALL
	};

private:
	std::vector<std::vector<BlockType>> m_data;
	void clear();

public:
	Grid();//int width, int height, int blockSize);
	BlockType at(int x, int y);
	void draw(SDL_Renderer *renderer);

	friend std::ostream& operator<<(std::ostream &out, const Grid &grid);
};
