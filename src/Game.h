#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include <vector>

class Game
{
  
 public:
  ~Game() {};
  // simply set the running variable to true
  bool init(const char* title, int posx, int posy, int width, int height, bool fullscreen);
  
  void render();
  void update();
  void handleEvents();
  void clean();
  SDL_Renderer* getRenderer() const { return m_pRenderer; }

  // a function to access the private running variable
  bool running() { return m_bRunning; }
 
  int m_currentFrame;  
  std::vector<GameObject*> m_gameObjects;

  static Game* Instance()
  {
    if(s_pInstance == 0)
      {
	s_pInstance = new Game();
	return s_pInstance;
      }
    return s_pInstance;
  }

 private:
  
  void draw();
  bool m_bRunning;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  Game() {};
  // create the s_pInstance member variable
  static Game* s_pInstance;
  // create the typedef
  
};

typedef Game TheGame;

#endif /* defined (__GAME__) */
