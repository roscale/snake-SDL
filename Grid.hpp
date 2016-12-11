#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

extern const int BLOCK_SIZE;

class Snake;
class Food;

class Grid
{
public:
	enum class BlockType
	{
		AIR,
		WALL
	};

private:
	int m_width;
	int m_height;
	std::vector<std::vector<BlockType>> m_data;

	Snake *m_snake = nullptr;
	Food *m_food = nullptr;

public:
	Grid(int width, int height);
	void addSnake(Snake *snake);
	void addFood(Food *food);

	void clear();

	bool checkCollision();

	void draw(SDL_Renderer *renderer);

	friend std::ostream& operator<<(std::ostream &out, const Grid &grid);
};
