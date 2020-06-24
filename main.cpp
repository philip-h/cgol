#include "Game.h"

Game *game = nullptr;

int main( void ) {

  game = new Game();
  game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

  while (game->isGameRunning()) {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();
  return 0;
}
