#include "Paddle.hpp"

Paddle::Paddle(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture, ren, x, y, w, h){
  collider.w = width*2;
  collider.h = height*2;
}

void Paddle::move(int x){
  if(xpos >= 0 || xpos <= 800){
    xpos += x;
    collider.x = xpos;
  }
}

void Paddle::handleInput(SDL_Event event){
  if(e.type == SDL_EVENT_KEY_DOWN){
    if(e.key.key == SDLK_LEFT){
      std::cout << "left" << std::endl;
    }
  }
}
