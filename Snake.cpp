#include "Snake.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "Point2D.hpp"
#include "Food.hpp"
#include "Grid.hpp"

Snake::Snake(Food *food) : p_food{food}
{
	food->addSnake(this);
	m_timer.start();
}

const Point2D& Snake::getPosition() const { return m_position; }

void Snake::turn(Snake::Direction newDir)
{
	if (input_locked)
		return;

	switch (newDir) {
		case Direction::UP:
			if (m_direction != Point2D{0, 1})
				m_direction = {0, -1};
			break;
		case Direction::DOWN:
			if (m_direction != Point2D{0, -1})
				m_direction = {0, 1};
			break;
		case Direction::LEFT:
			if (m_direction != Point2D{1, 0})
				m_direction = {-1, 0};
			break;
		case Direction::RIGHT:
			if (m_direction != Point2D{-1, 0})
				m_direction = {1, 0};
			break;
	}
	input_locked = true;
}

bool Snake::checkBitten()
{
	const int &head = m_tail.size()-1;
	for (int i = 0; i < head; i++)
		if (m_position == m_tail[i])
			return true;
	return false;
}

bool Snake::containsBlock(Point2D block)
{
	for (const auto& snakeBlock : m_tail)
		if (block == snakeBlock)
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
	std::cout << m_delay << " Tick: " << m_timer.getTicks() << '\n';
	if (m_timer.getTicks() >= m_delay)
	{
		push();
		m_timer.start();
		input_locked = false;
	}
}

void Snake::push()
{
	// keep length the same
	if (m_tail.size() >= m_length)
		m_tail.erase(m_tail.begin());

	m_position += m_direction;
	m_tail.push_back(m_position);
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
}

Snake& Snake::operator++()
{
	m_length++;
	return *this;
}
