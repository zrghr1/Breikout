#pragma once

#include "../Game.hpp"

class GameObject{
public:
  GameObject(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h);
  ~GameObject();

  void update();
  void render();

protected:
  int xpos;
  int ypos;
  int width;
  int height;

  SDL_Texture* objTexture;
  SDL_FRect srcRect, destRect;
  SDL_Renderer* renderer;
};
