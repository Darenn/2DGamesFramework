#include "PlayState.h"
#include "Game.h"
#include "LoaderParams.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include "TextureManager.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{ 
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
      TheGame::Instance()->getStateMachine()
	->pushState(new PauseState());
    }
  for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->update();
      }
}

void PlayState::render()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->draw();
      }
}

bool PlayState::onEnter()
{
  if (!TheTextureManager::Instance()->load("assets/heli.png",
					   "helicopter", TheGame::Instance()->getRenderer()))
    {
      return false;
    }  
  if (!TheTextureManager::Instance()->load("assets/heli2.png",
					   "helicopter2", TheGame::Instance()->getRenderer()))
    {
      return false;
    }
  m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128,55, "helicopter")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(400, 100, 128,55, "helicopter2")));
  std::cout << "entering PlayState\n";
  return true;
}

bool PlayState::onExit()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->clean();
    }
  m_gameObjects.clear();
  TheTextureManager::Instance()
  ->clearFromTextureMap("helicopter");
  std::cout << "exiting PlayState\n";
  return true;
}
