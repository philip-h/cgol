#pragma once

#include "SDL2/SDL.h"
#include <iostream>

class Game {
public:
  Game();
  ~Game();

  void init(const char* title, int width, int height, bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool isGameRunning() { return isRunning; }
  void togglePause() { isPaused = !isPaused; }

private:
  bool isRunning;
  bool isPaused;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

