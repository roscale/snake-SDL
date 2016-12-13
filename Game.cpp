#include "Game.hpp"
#include "Grid.hpp"
#include "Snake.hpp"
#include "Food.hpp"

Game::Game(Grid *grid, Snake *snake, Food *food) : m_grid{grid}, m_snake{snake}, m_food{food}
{}

bool Game::checkCollisions()
{
  m_snake->checkFoodEaten();
	if (m_snake->checkBitten())
		return true;

	if (m_grid->at(m_snake->m_position.x, m_snake->m_position.y) != Grid::BlockType::AIR)
    return true;

	return false;
}
