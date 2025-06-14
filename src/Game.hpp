#pragma once

#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
//#include "SDL3_ttf/SDL_ttf.h"
#include <iostream>
#include <vector>

class Game {
public: 
  Game();
  ~Game();

  void init(const char* title, int width, int height, bool fullscreen);

  void handleEvents();
  void handleInput();
  void update();
  void render();
  void clear();

  bool running() { return isRunning; }

private:
  //int state;
  int cnt = 0;
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;
};

