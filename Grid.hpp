#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

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
	const int m_width;
	const int m_height;
	const int m_blockSize;
	std::vector<std::vector<BlockType>> m_data;

	Snake *m_snake = nullptr;
	Food *m_food = nullptr;

	void clear();

public:
	Grid(int width, int height, int blockSize);
	void addSnake(Snake *snake);
	void addFood(Food *food);

	int getWidth() const;
	int getHeight() const;
	int getBlockSize() const;

	bool checkCollisions();

	void draw(SDL_Renderer *renderer);

	friend std::ostream& operator<<(std::ostream &out, const Grid &grid);

	friend class Snake;
	friend class Food;
	// friend void Snake::draw(SDL_Renderer *renderer);
	// friend void Food::draw(SDL_Renderer *renderer);
	// friend void Food::generate();

};
