#include "Game.hpp"
#include "utils/TextureManager.hpp"
#include "gameobjects/GameObject.hpp"

GameObject* bricks[40];

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
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      std::cout << "Renderer Created..." << std::endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

  int count = 0;
  for(int i = 0; i < sizeof(bricks); i++){
    if(i%40 == 39){
      count++;
    }
    std::cout << count << std::endl;
    bricks[i] = new GameObject("assets/2d/Brick.png", renderer, (i%40) * 80, count*40);
  }

  // Test brick
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
  for(int i = 0; i < sizeof(bricks); i++){
    bricks[i]->update();
  }
  //std::cout << cnt << std::endl;
}

void Game::render(){
  SDL_RenderClear(renderer);
  // Add renderables here

  for(int i = 0; i < sizeof(bricks); i++){
    bricks[i]->render();
  }
  // End here
  SDL_RenderPresent(renderer);
}

void Game::clear(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game Cleared" << std::endl;
}

