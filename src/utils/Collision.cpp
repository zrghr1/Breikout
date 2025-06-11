#include "Collision.hpp"

bool checkCollision( SDL_FRect a, SDL_FRect b ){
  float leftA, leftB;
  float rightA, rightB;
  float topA, topB;
  float bottomA, bottomB;

  // Calculate sides of both colliders
  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;
 
  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;
  
  //Check Collision
  if(bottomA <= topB){
    return false;
  }
  if(topA >= bottomB){
    return false;
  }
  if(rightA <= leftB){
    return false;
  }
  if(leftA >= rightB){
    return false;
  }

  return true;
}
