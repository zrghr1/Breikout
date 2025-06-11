#pragma once

#include "GameObject.hpp"

class Ball : public GameObject {
public:
  Ball();
  ~Ball();

  void move( SDL_FRect& wall);
  
private:
  int xvel, yvel;
  SDL_FRect collider;
}
