#include <SDL2/SDL.h>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Window.hpp"
#include "Point2D.hpp"
#include "Game.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

const int Grid::WIDTH = 20;
const int Grid::HEIGHT = 20;
const int Grid::BLOCK_SIZE = 20;

const int Window::WIDTH = Grid::WIDTH * Grid::BLOCK_SIZE;
const int Window::HEIGHT = Grid::HEIGHT * Grid::BLOCK_SIZE;

Grid *Game::p_grid = nullptr;
Snake *Game::p_snake = nullptr;
Food *Game::p_food = nullptr;

int main()
{
	assert(Grid::BLOCK_SIZE > 0);
	srand(time(0));

	Window::init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC | SDL_INIT_TIMER);
	Window::createWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Window::WIDTH, Window::HEIGHT, SDL_WINDOW_SHOWN);
	Window::createRenderer();

	Grid grid;
		std::cout << grid;
	Food food(&grid);
	Snake snake(&food);
	food.generate();

	Game::init(&grid, &snake, &food);
	// SDL_TimerID tick = SDL_AddTimer(50, Game::gameTick, nullptr);

	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
					break;
			}
			switch (e.type)
			{
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
						case SDLK_UP:
							snake.turn(Snake::Direction::UP); break;
						case SDLK_DOWN:
							snake.turn(Snake::Direction::DOWN); break;
						case SDLK_LEFT:
							snake.turn(Snake::Direction::LEFT); break;
						case SDLK_RIGHT:
							snake.turn(Snake::Direction::RIGHT); break;
						default:
							break;
					}
					break;
			}
		}
		SDL_SetRenderDrawColor(Window::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Window::renderer);

		if (Game::checkCollisions()) { exit(0); }
		Game::draw(Window::renderer);

		SDL_RenderPresent(Window::renderer);
		SDL_Delay(10);
	}

	SDL_Quit();
	return 0;
}
