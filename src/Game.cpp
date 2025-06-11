#include "Game.hpp"
#include "utils/TextureManager.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"

GameObject* brick;
Ball* ball;

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

  // Initialize Brick
  brick = new GameObject("assets/2d/Brick.png", renderer, 0, 0, 40, 20);

  // Initialize ball
  ball = new Ball("assets/2d/Ball.png", renderer, 400, 400, 10, 10);
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
  
  brick->update();
  //std::cout << cnt << std::endl;
}

void Game::render(){
  SDL_RenderClear(renderer);
  // Add renderables here

  brick->render();
  // End here
  SDL_RenderPresent(renderer);
}

void Game::clear(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game Cleared" << std::endl;
}

