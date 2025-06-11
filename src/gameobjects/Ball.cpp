#include "Ball.hpp"
#include "../utils/Collision.hpp"

Ball::Ball(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height)
: GameObject(texture,ren,x,y, width, height){
  
  collider.w = width;
  collider.h = height;
  
  xvel = 1;
  yvel = 1;
}

void Ball::move( SDL_FRect& wall){
  xpos += xvel;
  collider.x = xpos;

  if ((xpos < 0 ) || (xpos + collider.w > 800) || checkCollision(collider, wall)){
    xpos -= xvel;
    collider.x = xpos;
  }

  ypos += yvel;
  collider.y = ypos;

  if ((ypos < 0 ) || (ypos + collider.h > 800) || checkCollision(collider, wall)){
    ypos -= yvel;
    collider.y = ypos;
  }
}
