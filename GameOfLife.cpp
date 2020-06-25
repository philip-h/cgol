#include "GameOfLife.h"

GameOfLife::GameOfLife(SDL_Renderer* _renderer, int _screenWidth, int _screenHeight) {
  renderer = _renderer;
  screenWidth = _screenWidth;
  screenHeight = _screenHeight;

  // Calculate cell size based on preferred number of colums and the screen size
  cellWidth = int(screenWidth/cols);
  cellHeight = int(screenHeight/rows);

  createGosperGliderGun();
}

GameOfLife::~GameOfLife() {}

void GameOfLife::update() {
  // Temporary board for updates.
  std::array<bool,rows*cols> tempBoard;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int numNeighbours = getNeighbourCount(i, j);
      bool isCellAlive = board[i*rows + j];
      
      // Rules implemented for Conway's Game of Life
      if      (isCellAlive  && numNeighbours < 2)   tempBoard[i*rows + j] = false;
      else if (isCellAlive  && numNeighbours > 3)   tempBoard[i*rows + j] = false;
      else if (!isCellAlive && numNeighbours == 3 ) tempBoard[i*rows + j] = true;
      else                                          tempBoard[i*rows + j] = board[i*rows + j];
    }
  }

  // Copy from tempBoard to board
  board = tempBoard;
}

void GameOfLife::render() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // If alive colour is white
      if (board[i*rows + j])
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      // If dead, colour is black
      else
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

      SDL_Rect fillRect = {j*cellWidth, i*cellHeight, cellWidth, cellHeight};
      SDL_RenderFillRect(renderer, &fillRect);
    }
  }
}

int GameOfLife::getNeighbourCount(int row, int col) {
  // Edge cases (literally :D )
  int startR = (row - 1 < 0)    ? row : row - 1;
  int startC = (col - 1 < 0)    ? col : col - 1;
  int endR =   (row + 1 > rows) ? row : row + 1;
  int endC =   (col + 1 > cols) ? col : col + 1;

  int neighbourCount = 0;
  for (int i = startR; i <= endR; i++) {
    for (int j = startC; j <= endC; j++) {
      // Don't count yourself
      if (i == row && j == col) continue;
      if (board[i*rows + j] == 1) neighbourCount ++;
    }
  }
  return neighbourCount;
}

void GameOfLife::createGlider() {
  // By default, all cells are dead
  board.fill(false);

  // Except these ones!
  // ( Creates a Glider )
  board[50*rows + 49] = true;
  board[50*rows + 50] = true;
  board[50*rows + 51] = true;
  board[49*rows + 51] = true;
  board[48*rows + 50] = true;

}

void GameOfLife::createGosperGliderGun() {
  // By default, all cells are dead
  board.fill(false);

  // Except these ones!
  // ( Creates a Glider Gun )
  board[11*rows + 25] = true;

  board[12*rows + 23] = true;
  board[12*rows + 25] = true;

  board[13*rows + 13] = true;
  board[13*rows + 14] = true;
  board[13*rows + 21] = true;
  board[13*rows + 22] = true;
  board[13*rows + 35] = true;
  board[13*rows + 36] = true;

  board[14*rows + 12] = true;
  board[14*rows + 16] = true;
  board[14*rows + 21] = true;
  board[14*rows + 22] = true;
  board[14*rows + 35] = true;
  board[14*rows + 36] = true;

  board[15*rows + 1] = true;
  board[15*rows + 2] = true;
  board[15*rows + 11] = true;
  board[15*rows + 17] = true;
  board[15*rows + 21] = true;
  board[15*rows + 22] = true;


  board[16*rows + 1] = true;
  board[16*rows + 2] = true;
  board[16*rows + 11] = true;
  board[16*rows + 15] = true;
  board[16*rows + 17] = true;
  board[16*rows + 18] = true;
  board[16*rows + 23] = true;
  board[16*rows + 25] = true;

  board[17*rows + 11] = true;
  board[17*rows + 17] = true;
  board[17*rows + 25] = true;

  board[18*rows + 12] = true;
  board[18*rows + 16] = true;

  board[19*rows + 13] = true;
  board[19*rows + 14] = true;



}
