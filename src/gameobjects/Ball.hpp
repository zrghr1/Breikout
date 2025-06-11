#pragma once

#include "GameObject.hpp"

class Ball : public GameObject {
public:
  Ball(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height);
  ~Ball();

  void move(/* SDL_FRect& paddle */);
  
private:
  int xvel, yvel;
  SDL_FRect collider;
};
