#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game* Game::s_pInstance = 0;

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

  TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);  
  m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(250, 250, 128, 82, "animate")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(100, 150, 128, 82, "animate")));
  TheInputHandler::Instance()->initialiseJoysticks();
  m_bRunning = true;
  return true;
}

void Game::draw()
{
  for(std::vector<GameObject*>::size_type i = 0;
      i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->draw();
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
  TheInputHandler::Instance()->clean();
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::update()
{
  for(std::vector<GameObject*>::size_type i = 0; i !=
	m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->update();
    }
}
 

