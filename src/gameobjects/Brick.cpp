#include "Brick.hpp"

Brick::Brick(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture,ren,x,y, w, h){
  
  collider.w = width*2;
  collider.h = height*2;
}
