#pragma once

class Grid;
class Snake;
class Food;

class Game
{
private:
  Grid *p_grid = nullptr;
  Snake *p_snake = nullptr;
  Food *p_food = nullptr;

public:
  Game(Grid *grid, Snake *snake, Food *food);

  bool checkCollisions();
};
