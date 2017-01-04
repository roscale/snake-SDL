#include "Snake.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "Point2D.hpp"
#include "Food.hpp"
#include "Grid.hpp"

const std::map<Snake::Direction, Point2D> Snake::s_directionVectors =
{
	{ Snake::Direction::UP,		Point2D{0, -1} },
	{ Snake::Direction::DOWN,	Point2D{0, 1} },
	{ Snake::Direction::LEFT,	Point2D{-1, 0} },
	{ Snake::Direction::RIGHT,	Point2D{1, 0} }
};

Snake::Snake(Food *food) : p_food{food}
{
	food->addSnake(this);
	m_timer.start();
}

const Point2D& Snake::getPosition() const { return m_position; }

void Snake::turn(Snake::Direction newDir)
{
	// Filter by last direction taken
	Direction lastDirection;
	if (input_cache.size())
		lastDirection = input_cache[input_cache.size()-1];
	else
		lastDirection = m_direction;

	// Ignore if it's the same or opposite direction
	if (newDir == lastDirection || Snake::s_directionVectors.at(newDir) == -Snake::s_directionVectors.at(lastDirection))
		return;

	input_cache.push_back(newDir);

	if (input_cache.size() > Snake::max_input_cache_size)
		input_cache.erase(input_cache.begin());

	// There is one case where an invalid direction could be in the first position if you spam keys
	if (m_direction == input_cache[0] || Snake::s_directionVectors.at(m_direction) == -Snake::s_directionVectors.at(input_cache[0]))
		input_cache.erase(input_cache.begin());
}

bool Snake::checkBitten()
{
	const int &head = m_tail.size()-1;
	for (int i = 0; i < head; i++)
		if (m_position == m_tail[i])
			return true;
	return false;
}

bool Snake::containsPoint(Point2D point)
{
	for (const auto& snakeBlock : m_tail)
		if (point == snakeBlock)
			return true;
	return false;
}

void Snake::speedUp()
{
	// 98%
	m_delay *= 98;
	m_delay /= 100;

	m_delay = (m_delay < 0) ? 0 : m_delay;
}

void Snake::update()
{
	// std::cout << m_delay << " Tick: " << m_timer.getTicks() << '\n';
	if (m_timer.getTicks() >= m_delay)
	{
		push();
		m_timer.start();
	}
}

void Snake::push()
{
	for (auto& dir : input_cache)
		std::cout << Snake::s_directionVectors.at(dir) << " ";
	std::cout << '\n';

	if (input_cache.size())
	{
		m_direction = input_cache[0];
		input_cache.erase(input_cache.begin());
	}
	m_position += Snake::s_directionVectors.at(m_direction);
	m_tail.push_back(m_position);

	// Keep length the same
	if (m_tail.size() > m_length)
		m_tail.erase(m_tail.begin());
}

void Snake::draw(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	const int &blockSize = Grid::BLOCK_SIZE;
	for (const auto blockPos : m_tail)
	{
		SDL_Rect blockRect = {
			blockPos.x * blockSize,
			blockPos.y * blockSize,
			blockSize, blockSize };

		SDL_RenderFillRect(renderer, &blockRect);
	}

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

}

Snake& Snake::operator++()
{
	m_length++;
	return *this;
}
