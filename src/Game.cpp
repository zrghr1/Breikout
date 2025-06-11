#include "Game.hpp"
#include "utils/TextureManager.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"
#include "gameobjects/Paddle.hpp"

GameObject* brick;
Ball* ball;
Paddle* paddle;

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
  brick = new GameObject("assets/2d/Brick.png", renderer, 0, 0, 20, 40);

  // Initialize ball
  ball = new Ball("assets/2d/Ball.png", renderer, 400, 400, 10, 10);

  // Initialize Paddle
  paddle = new Paddle("assets/2d/Paddle.png", renderer, 400, 700, 10, 60);

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

  paddle->handleInput(event);
}

void Game::update(){
  cnt++;
  
  brick->update();
  ball->update();
  ball->move();
  paddle->move();
  //std::cout << cnt << std::endl;
}

void Game::render(){
  SDL_RenderClear(renderer);
  // Add renderables here

  brick->render();
  ball->render();
  paddle->render();
  // End here
  SDL_RenderPresent(renderer);
}

void Game::clear(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  free(brick);
  free(ball);
  free(paddle);

  std::cout << "Game Cleared" << std::endl;
}

