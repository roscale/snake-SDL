#pragma once

class Grid;
class Snake;
class Food;

class Game
{
private:
  Grid *m_grid = nullptr;
  Snake *m_snake = nullptr;
  Food *m_food = nullptr;

public:
  Game(Grid *grid, Snake *snake, Food *food);

  bool checkCollisions();
};
