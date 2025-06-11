#include "Paddle.hpp"

Paddle::Paddle(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture, ren, x, y, w, h){
  collider.w = width*2;
  collider.h = height*2;
}

void Paddle::handleInput(SDL_Event e){
  if(e.type == SDL_EVENT_KEY_DOWN){
    if(e.key.key == SDLK_LEFT){
      xvel = -1;
      std::cout << xvel << std::endl;
    }
    if(e.key.key == SDLK_RIGHT){
      xvel = 1;
      std::cout << xvel << std::endl;
    }
  }
  if(e.type == SDL_EVENT_KEY_UP){
    if(e.key.key == SDLK_LEFT || e.key.key == SDLK_RIGHT){
      xvel = 0;
      std::cout << xvel << std::endl;
    }
  }
}

void Paddle::move(){
  if(xpos >= 0 && xpos <= 800){
    xpos += xvel;
    collider.x = xpos;
  }
}
