#include <SDL2/SDL.h>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sdl_helper.hpp"
#include "Point2D.hpp"
#include "Game.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 40;
const int BLOCK_SIZE = 20;

const int WINDOW_WIDTH = GRID_WIDTH * BLOCK_SIZE;
const int WINDOW_HEIGHT = GRID_WIDTH * BLOCK_SIZE;


int main()
{
	assert(BLOCK_SIZE > 0);
	srand(time(0));

	MySDL::init(SDL_INIT_VIDEO);
	SDL_Window* window = MySDL::createWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = MySDL::createRenderer(window);

	Grid grid(WINDOW_WIDTH / BLOCK_SIZE, WINDOW_HEIGHT / BLOCK_SIZE, BLOCK_SIZE);
	std::cout << grid;

	Snake snake;
	Food food;

	grid.addSnake(&snake);
	grid.addFood(&food);
	snake.addFood(&food);
	food.generate();

	Game game(&grid, &snake, &food);

	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
					break;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym) {
					case SDLK_UP:
						snake.up(); break;
					case SDLK_DOWN:
						snake.down(); break;
					case SDLK_LEFT:
						snake.left(); break;
					case SDLK_RIGHT:
						snake.right(); break;
					default:
						break;
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		if (game.checkCollisions()) { break; }
		snake.update();

		grid.draw(renderer);
		food.draw(renderer);
		snake.draw(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(50);
	}

	SDL_Quit();
	return 0;
}
