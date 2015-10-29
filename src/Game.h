#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

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
  std::vector<GameObject*> m_gameObjects;
  GameObject* m_enemy1;
  GameObject* m_enemy2;
  GameObject* m_enemy3;
  GameObject* m_player;

 private:
  
  void draw();
  bool m_bRunning;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

};

#endif /* defined (__GAME__) */
