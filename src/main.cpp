#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char* args[]) 
{
  TheGame::Instance()->init("Chapter 1 : setting up SDL",
	       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	       640, 480,
	       false);
  while (TheGame::Instance()->running())
    { 
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(20);
    }

  TheGame::Instance()->clean();

  return 0;
}
