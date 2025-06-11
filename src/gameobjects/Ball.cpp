#include "Ball.hpp"

Ball::Ball(const char* texture, SDL_Renderer* ren, int x, int y, int w, int h)
: GameObject(texture,ren,x,y, w, h){
  
  collider.w = width*2;
  collider.h = height*2;
  
  xvel = 2;
  yvel = 4;
}

void Ball::move(Paddle* paddle){

  if ((xpos < 0 ) || (xpos + collider.w > 800) /* || checkCollision(collider, wall) */){
    xvel = -xvel;
    xpos += xvel;
    collider.x = xpos;
  }

  if ((ypos < 0 ) || (ypos + collider.h > 800) /* || checkCollision(collider, wall) */){
    yvel = -yvel;
    ypos += yvel;
    collider.y = ypos;
  }

  if(ypos + 20 > paddle->ypos && ypos < paddle->ypos + 20){
    if(xpos > paddle->xpos && xpos< paddle->xpos + 120){
      yvel= -4;
      if(xvel < 0) {
        xvel = -2;
      } else {
        xvel = 2;
      }

      if(xpos< paddle->xpos + 30) {
        yvel = -2;
        xvel = -4;
      }else if ( xpos > paddle->xpos + 90){
        yvel = -2;
        xvel = 4;
      }
      ypos += yvel;
      collider.y = ypos;
      xpos += xvel;
      collider.x = xpos;
    }
  }

  xpos += xvel;
  collider.x = xpos;

  ypos += yvel;
  collider.y = ypos;
}

int Ball::collideBrick(Brick* brick){

  if(xpos + 20 > brick->xpos && xpos < brick->xpos + 80){
    if(ypos + 20 > brick->ypos && ypos < brick->ypos + 40){
      if(xpos + 20 > brick->xpos + 80 || xpos < brick->xpos){
        xvel = -xvel;
      }
      if(ypos + 20 > brick->ypos + 40 || ypos < brick->ypos){
        yvel = -yvel;
      }
      std::cout << "brick hit" << std::endl;
      free(brick);
      return 1;
    }
  }
  return 0;
}
