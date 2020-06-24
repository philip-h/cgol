#pragma once

#include "Game.h"

class GameOfLife {

public:
  GameOfLife(SDL_Renderer* _renderer, int _screenWidth, int _screenHeight);
  ~GameOfLife();

  void update();
  void render();

private:
  SDL_Renderer* renderer;

  static const int cols = 100;
  static const int rows = 100;
  bool board[cols][rows];
  int screenWidth, screenHeight;
  int cellWidth, cellHeight;

  int getNeighbourCount(int x, int i);

};
