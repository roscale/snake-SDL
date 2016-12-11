#include "Snake.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "Point2D.hpp"
#include "Food.hpp"

Point2D Snake::getPosition() const { return m_position; }

Snake& Snake::operator++()
{
	m_length++;
	return *this;
}

void Snake::up()
{
	if (m_direction != Point2D{0, 1})
		m_direction.set(0, -1);
}
void Snake::down()
{
	if (m_direction != Point2D{0, -1})
		m_direction.set(0, 1);
}
void Snake::left()
{
	if (m_direction != Point2D{1, 0})
		m_direction.set(-1, 0);
}
void Snake::right()
{
	if (m_direction != Point2D{-1, 0})
		m_direction.set(1, 0);
}

bool Snake::checkBiten()
{
	for (int i = 0; i < m_tail.size()-1; i++)
		if (m_position == m_tail[i])
			return true;
	return false;
}

bool Snake::checkFoodEaten(Food *food)
{
	if (getPosition() == food->getPosition())
	{
		++(*this);
		food->generate();
	}
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
		for (int i = 0; i < m_tail.size()-1; i++)
			m_tail[i] = m_tail[i+1];

		m_position += m_direction;
		m_tail[m_tail.size()-1] = m_position;
	}
}

void Snake::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	for (const auto blockPoint : m_tail)
	{
		SDL_Rect blockRect = {
			blockPoint.getX() * BLOCK_SIZE,
			blockPoint.getY() * BLOCK_SIZE,
			BLOCK_SIZE, BLOCK_SIZE };

		SDL_RenderFillRect(renderer, &blockRect);
	}
}
