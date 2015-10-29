#include <SDL2/SDL.h>
#include "Game.h"

Game* g_game = NULL;

int main(int argc, char* args[]) 
{
  g_game = new Game();
  g_game->init("Chapter 1 : setting up SDL",
	       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	       640, 480,
	       false);
  while (g_game->running())
    { 
      g_game->handleEvents();
      g_game->update();
      g_game->render();
      SDL_Delay(20);
    }

  g_game->clean();

  return 0;
}
