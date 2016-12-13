#include "Game.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

Game::Game(Grid *grid, Snake *snake, Food *food) : p_grid{grid}, p_snake{snake}, p_food{food}
{}

bool Game::checkCollisions()
{
	p_snake->checkFoodEaten();
	if (p_snake->checkBitten())
		return true;

	if (p_grid->at(p_snake->getPosition().x, p_snake->getPosition().y) != Grid::BlockType::AIR)
		return true;

	return false;
}
