#include "Game.hpp"

Game* game = nullptr;

int main(int argc, const char * argv[]) {

  game = new Game();

  game->init("Breakout", 
             SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED,
             800,
             600,
             false);

  while (game->running()){
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clear();

  return 0;
}
