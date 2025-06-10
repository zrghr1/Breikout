#include "Game.hpp"

SDL_Texture* brick;

Game::Game() {

}

Game::~Game(){

}

void Game::init(const char *title, int width, int height, bool fullscreen){

  int flags = 0;
  if(fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if(SDL_Init(0)){
    std::cout << "Subsystem Initialized..." << std::endl;

    window = SDL_CreateWindow(title, width, height, flags);
    if(window){
      std::cout << "Window Created..." << std::endl;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created..." << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

  // Test brick
  SDL_Surface* tmpSurface = IMG_Load("assets/brick.png");
  brick = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type) {
    case SDL_EVENT_QUIT: 
      isRunning = false;
      break;
    default:
      break;
  }
}

void Game::update(){
  cnt++;
}

void Game::render(){
  SDL_RenderClear(renderer);
  // Add renderables here
  SDL_RenderCopy(renderer, brick, NULL, NULL);
  // End here
  SDL_RenderPresent(renderer);
}

void Game::clear(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game Cleared" << std::endl;
}

