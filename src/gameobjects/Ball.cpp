#include "Ball.hpp"
#include "../utils/Collision.hpp"

Ball::Ball(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture,ren,x,y, w, h){
  
  collider.w = width*2;
  collider.h = height*2;
  
  xvel = 2;
  yvel = 3;
}

void Ball::move(Paddle* paddle){
  xpos += xvel;
  collider.x = xpos;

  if ((xpos < 0 ) || (xpos + collider.w > 800) /* || checkCollision(collider, wall) */){
    xvel = -xvel;
    xpos += xvel;
    collider.x = xpos;
  }

  ypos += yvel;
  collider.y = ypos;

  if ((ypos < 0 ) || (ypos + collider.h > 800) /* || checkCollision(collider, wall) */){
    yvel = -yvel;
    ypos += yvel;
    collider.y = ypos;
  }

  std::cout << paddle->xpos << std::endl;
}
