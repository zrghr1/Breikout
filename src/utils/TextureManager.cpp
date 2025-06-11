#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SLD_Renderer* ren){
  SDL_Surface* tmpSurface = IMG_Load(texture);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
  SDL_DestroySurface(tmpSurface);

  return tex;
}
