#include "globals.hpp"
#include "Snake.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "Point2D.hpp"
#include "Food.hpp"
#include "Grid.hpp"

Snake::Snake(Grid *grid, Food *food) : p_grid{grid}, p_food{food}
{
	food->addSnake(this);
}

const Point2D& Snake::getPosition() const { return m_position; }

void Snake::up()
{
	if (m_direction != Point2D{0, 1})
		m_direction = {0, -1};
}
void Snake::down()
{
	if (m_direction != Point2D{0, -1})
		m_direction = {0, 1};
}
void Snake::left()
{
	if (m_direction != Point2D{1, 0})
		m_direction = {-1, 0};
}
void Snake::right()
{
	if (m_direction != Point2D{-1, 0})
		m_direction = {1, 0};
}

bool Snake::checkBitten()
{
	const int &head = m_tail.size()-1;
	for (int i = 0; i < head; i++)
		if (m_position == m_tail[i])
			return true;
	return false;
}

bool Snake::checkFoodEaten()
{
	if (getPosition() == p_food->getPosition())
	{
		p_food->generate();
		++(*this);
	}
}

bool Snake::containsBlock(Point2D block)
{
	for (const auto& snakeBlock : m_tail)
		if (block == snakeBlock)
			return true;
	return false;
}

void Snake::update()
{
	if (m_tail.size() < m_length)
	{
		m_position += m_direction;
		m_tail.push_back(m_position);
	}
	else
	{
		// shift all elements to the left
		const int &head = m_tail.size()-1;
		for (int i = 0; i < head; i++)
			m_tail[i] = m_tail[i+1];

		m_position += m_direction;
		m_tail[head] = m_position;
	}
}

void Snake::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	const int &blockSize = BLOCK_SIZE;
	for (const auto blockPos : m_tail)
	{
		SDL_Rect blockRect = {
			blockPos.x * blockSize,
			blockPos.y * blockSize,
			blockSize, blockSize };

		SDL_RenderFillRect(renderer, &blockRect);
	}
}

Snake& Snake::operator++()
{
	m_length++;
	return *this;
}
