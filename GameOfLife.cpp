#include "GameOfLife.h"

GameOfLife::GameOfLife(SDL_Renderer* _renderer, int _screenWidth, int _screenHeight) {
  renderer = _renderer;
  screenWidth = _screenWidth;
  screenHeight = _screenHeight;

  cellWidth = int(screenWidth/cols);
  cellHeight = int(screenHeight/rows);


  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i][j] = false;
    }
  }

  board[50][49] = true;
  board[50][50] = true;
  board[50][51] = true;
  board[49][51] = true;
  board[48][50] = true;
}

GameOfLife::~GameOfLife() {}

void GameOfLife::update() {
  bool tempBoard [rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int numNeighbours = getNeighbourCount(i, j);
      bool isCellAlive = board[i][j];

      
      if      (isCellAlive  && numNeighbours < 2)   tempBoard[i][j] = false;
      else if (isCellAlive  && numNeighbours > 3)   tempBoard[i][j] = false;
      else if (!isCellAlive && numNeighbours == 3 ) tempBoard[i][j] = true;
      else                                          tempBoard[i][j] = board[i][j];

    }
  }

  // Copy from temp to board
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i][j] = tempBoard[i][j];
    }
  }

}

void GameOfLife::render() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (board[i][j])
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      else
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

      SDL_Rect fillRect = {j*cellWidth, i*cellHeight, cellWidth, cellHeight};
      SDL_RenderFillRect(renderer, &fillRect);
    }
  }
}

int GameOfLife::getNeighbourCount(int row, int col) {
  int startR = (row - 1 < 0)    ? row : row - 1;
  int startC = (col - 1 < 0)    ? col : col - 1;
  int endR =   (row + 1 > rows) ? row : row + 1;
  int endC =   (col + 1 > cols) ? col : col + 1;

  int neighbourCount = 0;
  for (int i = startR; i <= endR; i++) {
    for (int j = startC; j <= endC; j++) {
      // Don't count yourself
      if (i == row && j == col) continue;
      if (board[i][j] == 1) neighbourCount ++;
    }
  }
  return neighbourCount;
}
