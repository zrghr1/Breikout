#include "Game.hpp"
#include "utils/TextureManager.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"
#include "gameobjects/Brick.hpp"
#include "gameobjects/Paddle.hpp"

GameObject* startScreen;
GameObject* badEnding;
GameObject* midEnding;
GameObject* goodEnding;
GameObject* winEnding;

std::vector<Brick*> bricks;
const int rows = 8;
const int cols = 10;

Ball* ball;
Paddle* paddle;

int score;
int state;

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
  
  // Initialize SDL3-ttf
  /*if(TTF_Init() != 0){
    std::cout << "SDL3_ttf failed initialization" << std::endl;
    isRunning = false;
  }*/

  // Init startScreen
  startScreen = new GameObject("assets/2d/StartScreen.png", renderer, 200, 200, 200, 200);

  // Init Ending Screens
  badEnding = new GameObject("assets/2d/BadEnding.png", renderer, 200, 200, 200, 200);
  midEnding = new GameObject("assets/2d/MidEnding.png", renderer, 200, 200, 200, 200);
  goodEnding = new GameObject("assets/2d/GoodEnding.png", renderer, 200, 200, 200, 200);
  winEnding = new GameObject("assets/2d/WinEnding.png", renderer, 200, 200, 200, 200);

  // Initialize Bricks
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      Brick* brick = new Brick("assets/2d/Brick.png", renderer, col*80, row*40, 40, 20);
      bricks.push_back(brick);
    }
  }

  // Initialize ball
  ball = new Ball("assets/2d/Ball.png", renderer, 400, 400, 10, 10);

  // Initialize Paddle
  paddle = new Paddle("assets/2d/Paddle.png", renderer, 340, 700, 60, 10);

  // Initialize Score
  score = 0;
  state = 0;

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

  if(event.type == SDL_EVENT_KEY_DOWN){
    if(event.key.key == SDLK_ESCAPE){
      if(state == 0){
        state = 1;
      }else if(state == 2){
        isRunning=false;
      }
      std::cout << state << std::endl;
    }
  }

  paddle->handleInput(event);
}

void Game::update(){
  if(state == 0) {
    startScreen->update();
  } else if (state == 1){
    cnt++;
   
    ball->update();
    int ballMove = ball->move(paddle);
    if(ballMove == 2){
      state = 2;
    }
    for(int i = 0; i < rows*cols; i++){
      bricks[i]->update();

      int brickHit = ball->collideBrick(bricks[i]);
      if(brickHit == 1){
        score++;
        std::cout << score << std::endl;
      }
    }
    
    paddle->update();
    paddle->move();
    //std::cout << cnt << std::endl;
  } else if (state == 2){
    if(score < 5){
      badEnding->update();
    }else if(score < 15){
      midEnding->update();
    }else if(score < 39){
      goodEnding->update();
    }else{
      winEnding->update();
    }
  }
}

void Game::render(){
  SDL_RenderClear(renderer);
  // Add renderables here
  if (state == 0){
    startScreen->render();
  } else if (state == 1){

    for(int i = 0; i < rows*cols; i++){
      bricks[i]->render();
    }
    ball->render();
    paddle->render();
  }else if (state == 2){
    if(score < 10){
      badEnding->render();
    }else if(score < 25){
      midEnding->render();
    }else if(score < 35){
      goodEnding->render();
    }else{
      winEnding->render();
    }
  }
  // End here
  SDL_RenderPresent(renderer);
}

void Game::clear(){

  /*for(int i = 0; i < rows*cols; i++){
    free(bricks[i]);
  }*/

  free(ball);
  free(paddle);
  free(startScreen);

  free(badEnding);
  free(midEnding);
  free(goodEnding);
  free(winEnding);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game Cleared" << std::endl;
}

