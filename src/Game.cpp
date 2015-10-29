#include "Game.h"

bool Game::init(const char* title, int posx, int posy,
	  int width, int height, bool fullscreen)
{
  int flags(0);
  if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; } 
  // initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
      std::cout << "SDL_Init succeeded" << std::endl;
      m_pWindow = SDL_CreateWindow(title, posx, posy,
				   width, height, flags);
      if (m_pWindow != 0) 
	{
	  std::cout << "SDL_CreateWindow succeeded" << std::endl;
	  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	  if (m_pRenderer != 0)
	    {
	      std::cout << "SDL_CreateRenderer succeeded" << std::endl;
	      SDL_SetRenderDrawColor(m_pRenderer,
				     255,0 , 0,255);
	    }
	  else
	    {
	      std::cout << "SDL_CreateRenderer fail" << std::endl;
	      return false;
	    }
	}
      else 
	{
	  std::cout << "SDL_CreateWindow fail" << std::endl;
	  return false;
	}	    
    }
  else // SDL could not be initialized 
    {
      std::cout << "SDL_Init fail" << std::endl;
      return false;
    }
  std::cout << "Init succeeded" << std::endl;

  m_player = new Player();
  m_enemy1 = new Enemy();
  m_enemy2 = new Enemy();
  m_enemy3 = new Enemy();
  m_gameObjects.push_back(m_player);
  m_gameObjects.push_back(m_enemy1);
  m_gameObjects.push_back(m_enemy2);
  m_gameObjects.push_back(m_enemy3);
  TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);
  m_player->load(0, 0, 128, 82, "animate");
  m_enemy1->load(100, 100, 128, 82, "animate");
  m_enemy2->load(250, 250, 128, 82, "animate");
  m_enemy3->load(100, 150, 128, 82, "animate");
  m_bRunning = true;
  return true;
}

void Game::draw()
{
  for(std::vector<GameObject*>::size_type i = 0;
      i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->draw(m_pRenderer);
    }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  Game::draw();
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  std::cout << "Cleaning game" << std::endl;
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  m_bRunning = false;
	  break;
	default:
	  break;
	}
    }
}

void Game::update()
{
  for(std::vector<GameObject*>::size_type i = 0; i !=
	m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->update();
    }
}
 

