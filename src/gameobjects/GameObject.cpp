#include "GameObject.hpp"
#include "../utils/TextureManager.hpp"

GameObject::GameObject(const char* texture, SDL_Renderer* ren, int x, int y, int width, int height){
  renderer = ren;
  objTexture = TextureManager::LoadTexture(texture, ren);

  xpos = x;
  ypos = y;

  srcRect.h = width;
  srcRect.w = height;
}

void GameObject::update(){
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w * 2;
  destRect.h = srcRect.h * 2;
}

void GameObject::render(){
  SDL_RenderTexture(renderer, objTexture, &srcRect, &destRect);
}
