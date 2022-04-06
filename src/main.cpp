//
// Created by neljn on 3/20/22.
//
#include "Game.h"

int main(int argc, char *argv[]) {

    SDL_SetMainReady();

    Game game;

  game.Initialize();
  game.Run();
  game.Destroy();

  return 0;
}
