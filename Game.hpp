#pragma once

#include <SDL2/SDL.h>
#include <cstdint>

class Grid;
class Snake;
class Food;

class Game
{
public:
	static Grid *p_grid;
	static Snake *p_snake;
	static Food *p_food;

	static void init(Grid *grid, Snake *snake, Food *food);
	static uint32_t gameTick(uint32_t interval, void *param);

	static bool checkCollisions();
	static void draw(SDL_Renderer *renderer);
};
