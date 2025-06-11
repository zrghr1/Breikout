#include "Ball.hpp"

Ball::Ball(){
  collider.w = 20;
  collider.h = 20;
  
  xvel = 0;
  yvel = 0;
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
