////
//// Created by neljn on 3/20/22.
////

#include "Game.h"
#include <iostream>

Game::Game() {
  isRunning = false;
  std::cout << "Game constructor called" << std::endl;
}

Game::~Game() { std::cout << "Game destructor called" << std::endl; }

void Game::Initialize() {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << SDL_GetError() << std::endl;
    return;
  }

  window = SDL_CreateWindow("The Adventure Engine", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  isRunning = true;
}
void Game::Run() {

  while (isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}
void Game::ProcessInput() {
  SDL_Event sdlEvent;
  while (SDL_PollEvent(&sdlEvent)) {
    switch (sdlEvent.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
        break;
      }
    }
  }
}
void Game::Update() {}
void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
}
void Game::Destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
