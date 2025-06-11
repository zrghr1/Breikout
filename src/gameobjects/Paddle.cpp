#include "Paddle.hpp"

Paddle::Paddle(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture, ren, x, y, w, h){
  collider.w = w*2;
  collider.h = h*2;
  xvel = 0;
}

void Paddle::handleInput(SDL_Event e){
  if(e.type == SDL_EVENT_KEY_DOWN){
    if(e.key.key == SDLK_LEFT){
      xvel = -3;
    }
    if(e.key.key == SDLK_RIGHT){
      xvel = 3;
    }
  }
  if(e.type == SDL_EVENT_KEY_UP){
    if(e.key.key == SDLK_LEFT || e.key.key == SDLK_RIGHT){
      xvel = 0;
    }
  }
}

void Paddle::move(){
  if(xpos > 0 && xpos < 800-collider.w){
    xpos += xvel;
    collider.x = xpos;
  } else if(xpos < 0) {
    xpos = 1;
    collider.x = xpos;
  } else {
    xpos = 799-collider.w;
    collider.x = xpos;
  }
}
