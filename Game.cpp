#include "Game.h"
#include "GameOfLife.h"

// Current game to run
GameOfLife* gol;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int width, int height, bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL Initialised" << std::endl;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window) {
      std::cout << "Window created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      std::cout << "Renderer created" << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

  gol = new GameOfLife(renderer, 800, 800);
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym) {
        case SDLK_p:
          togglePause();
          break;

        case SDLK_ESCAPE:
          isRunning = false;
          break;
      }
  }
}

void Game::update() {
  if (!isPaused) {
    gol->update();
  }
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);

  gol->render();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned" << std::endl;
}



