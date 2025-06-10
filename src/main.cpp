#include "Game.hpp"

Game* game = nullptr;

int main(int argc, char * argv[]) {

  game = new Game();

  game->init("Breakout", 
             800,
             800,
             false);

  while (game->running()){
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clear();

  return 0;
}
