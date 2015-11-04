#include "PlayState.h"
#include "Game.h"
#include "LoaderParams.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include "TextureManager.h"
#include "PauseState.h"
#include "SDLGameObject.h"
#include "GameOverState.h"

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
  if(checkCollision(dynamic_cast<SDLGameObject*>
		    (m_gameObjects[0]), dynamic_cast<SDLGameObject*>
		    (m_gameObjects[1])))
    {
      TheGame::Instance()->getStateMachine()
	->pushState(new GameOverState());
    }
}

void PlayState::render()
{
  for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->draw();
      }
}

bool PlayState::onEnter()
{
  // if (!TheTextureManager::Instance()->load("assets/heli.png",
  // 					   "helicopter", TheGame::Instance()->getRenderer()))
  //   {
  //     return false;
  //   }  
  // if (!TheTextureManager::Instance()->load("assets/heli2.png",
  // 					   "helicopter2", TheGame::Instance()->getRenderer()))
  //   {
  //     return false;
  //   }
  // m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128,55, "helicopter")));
  // m_gameObjects.push_back(new Enemy(new LoaderParams(400, 100, 128,55, "helicopter2")));
  std::cout << "entering PlayState\n";
  return true;
}

bool PlayState::onExit()
{
  // for(unsigned int i = 0; i < m_gameObjects.size(); i++)
  //   {
  //     m_gameObjects[i]->clean();
  //   }
  // m_gameObjects.clear();
  // // clear the texture manager
  // for(int i = 0; i < m_textureIDList.size(); i++)
  //   {
  //     TheTextureManager::Instance()->
  // 	clearFromTextureMap(m_textureIDList[i]);
  //   }
  std::cout << "exiting PlayState\n";
  return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;
  leftA = p1->getPosition().getX();
  rightA = p1->getPosition().getX() + p1->getWidth();
  topA = p1->getPosition().getY();
  bottomA = p1->getPosition().getY() + p1->getHeight();
  //Calculate the sides of rect B
  leftB = p2->getPosition().getX();
  rightB = p2->getPosition().getX() + p2->getWidth();
  topB = p2->getPosition().getY();
  bottomB = p2->getPosition().getY() + p2->getHeight();
  //If any of the sides from A
  if( bottomA <= topB ){return false; }
  if( topA >= bottomB ){return false; }
  if( rightA <= leftB ){return false; }
  if( leftA >= rightB ){return false;}

  return true;
}
