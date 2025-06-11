#pragma once

#include "GameObject.hpp"

class Paddle : public GameObject {
public:
  Paddle(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height);
  ~Paddle();

  void handleInput(SDL_Event event);
  void move();
  SDL_FRect collider;

private:
  int xvel;
};
