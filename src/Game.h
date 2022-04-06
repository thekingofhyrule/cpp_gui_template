////
//// Created by neljn on 3/20/22.
////
#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED
#include <SDL.h>

class Game {

public:
  Game();
  ~Game();

  void Initialize();
  void Run();
  void ProcessInput();
  void Update();
  void Render();
  void Destroy();

private:
  bool isRunning;

  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif // THEADVENTUREENGINE_GAME_H
