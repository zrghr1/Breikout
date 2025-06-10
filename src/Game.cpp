#include <Game.hpp>

Game::Game() {

}

Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){

  int flags = 0;
  if(fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    std::cout << "Subsystem Initialized!..." std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, height, flags);
    if(window){
      std::cout << "Window created" << std::endl;
    }
  }
}

void handleEvents(){

}

void update(){

}

void render(){

}

void clear(){

}

