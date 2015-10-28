#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"

class Game
{
  
 public:
  
  Game() {};
  ~Game() {};
  // simply set the running variable to true
  bool init(const char* title, int posx, int posy, int width, int height, bool fullscreen);
  
  void render();
  void update();
  void handleEvents();
  void clean();

  // a function to access the private running variable
  bool running() { return m_bRunning; }
 
  int m_currentFrame;

 private:
  
  bool m_bRunning;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

};

#endif /* defined (__GAME__) */
