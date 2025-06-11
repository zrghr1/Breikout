#include "GameObject.hpp"
#include "../utils/TextureManager.hpp"

GameObject::GameObject(const char* texture, SDL_Renderer* ren){
  renderer = ren;
  objTexture = TextureManager::LoadTexture(texture, ren)
}

void GameObject::update(){
  xpos = 0;
  ypos = 0;

  srcRect.h = 20;
  srcRect.w = 40;
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
