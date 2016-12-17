#include "Window.hpp"
#include "Game.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include <SDL2/SDL.h>
#include <cstdint>

void Game::init(Grid *grid, Snake *snake, Food *food)
{
	p_grid = grid;
	p_snake = snake;
	p_food = food;
}

uint32_t Game::gameTick(uint32_t interval, void *param)
{
	SDL_Event event;
	event.type = SDL_USEREVENT;

	SDL_PushEvent(&event);

	#include <iostream>
	std::cout << interval << '\n' << std::flush;

	return interval;
}

bool Game::checkCollisions()
{
	if (p_food->checkEaten())
	{
		p_food->generate();
		++(*p_snake);
		p_snake->speedUp();
	}
	if (p_snake->checkBitten())
		return true;

	if (p_grid->at(p_snake->getPosition().x, p_snake->getPosition().y) != Grid::BlockType::AIR)
		return true;

	p_snake->update();

	return false;
}

void Game::draw(SDL_Renderer *renderer)
{
	p_grid->draw(renderer);
	p_food->draw(renderer);
	p_snake->draw(renderer);
}
