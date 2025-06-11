#pragma once

#include "GameObject.hpp"

class Brick : public GameObject {
public:
  Brick(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height);
  ~Brick();

  SDL_FRect collider;
};
