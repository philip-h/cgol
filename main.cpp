#include "Game.h"

Game *game = nullptr;

int main( void ) {

  const int FPS = 15;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  game = new Game();
  game->init("Game", 800, 800, false);

  while (game->isGameRunning()) {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();
  return 0;
}
