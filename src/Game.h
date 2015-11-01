#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "GameStateMachine.h"

class Game
{
  
 public:
  ~Game() {};
  bool init(const char* title, int posx, int posy, int width, int height, bool fullscreen);  
  void render();
  void update();
  void handleEvents();
  void clean();
  void quit() { m_bRunning = false; };
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
  GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
  
 private:
  
  void draw();
  bool m_bRunning;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  Game() {};
  // create the s_pInstance member variable
  static Game* s_pInstance;
  // create the typedef
  GameStateMachine* m_pGameStateMachine;
  
};

typedef Game TheGame;

#endif /* defined (__GAME__) */
