#pragma once

#include "GameObject.hpp"

class Paddle : public GameObject {
public:
  Paddle(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height);
  ~Paddle();

  void handleInput(SDL_Event event);
  void update();
  void render();
  void move();

private:
  int xvel;
  SDL_FRect collider;
};
