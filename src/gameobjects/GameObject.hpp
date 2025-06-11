#pragma once

#include "../Game.hpp"

class GameObject{
public:
  GameObject(const char* texture, SDL_Renderer* ren)
  ~GameObject();

  void update();
  void render();

private:
  int xpos;
  int ypos;

  SDL_Texture* texture;
  SDL_Rect srcRect, destRect;
  SDL_Renderer* renderer;

}
