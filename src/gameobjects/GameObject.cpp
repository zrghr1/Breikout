#include "GameObject.hpp"
#include "../utils/TextureManager.hpp"

GameObject::GameObject(const char* texture, SDL_Renderer* ren){
  renderer = ren;
  objTexture = TextureManager::LoadTexture(texture, ren)
}
