#include "GameOverState.h"
#include <vector>
#include <iostream>
#include "MenuButton.h"
#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
  TheGame::Instance()->getStateMachine()->changeState(new
						      MainMenuState());
}

void GameOverState::s_restartPlay()
{
  TheGame::Instance()->getStateMachine()->changeState(new
						      PlayState());
}

bool GameOverState::onEnter()
{
  // if(!TheTextureManager::Instance()->load("assets/gameover.png",
  // 					  "gameovertext", TheGame::Instance()->getRenderer()))
  //   {
  //     return false;
  //   }
  // if(!TheTextureManager::Instance()->load("assets/main.png",
  // 					  "mainbutton", TheGame::Instance()->getRenderer()))
  //   {
  //     return false;
  //   }
  // if(!TheTextureManager::Instance()->load("assets/restart.png",
  // 					  "restartbutton", TheGame::Instance()->getRenderer()))
  //   {
  //     return false;
  //   }
  // GameObject* gameOverText = new AnimatedGraphic(new
  // 						 LoaderParams(200, 100, 190, 30, "gameovertext", 2), 2);
  // GameObject* button1 = new MenuButton(new LoaderParams(200, 200,
  // 							200, 80, "mainbutton",3), s_gameOverToMain);
  // GameObject* button2 = new MenuButton(new LoaderParams(200, 300,
  // 							200, 80, "restartbutton",3), s_restartPlay);
  // m_gameObjects.push_back(gameOverText);
  // m_gameObjects.push_back(button1);
  // m_gameObjects.push_back(button2);
  std::cout << "entering GameOverState\n";
  return true;
}

void GameOverState::update()
{
  for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {       
      m_gameObjects[i]->update();     
    }
}

bool GameOverState::onExit()
{
  // clear the texture manager
  // for(int i = 0; i < m_textureIDList.size(); i++)
  //   {
  //     TheTextureManager::Instance()->
  // 	clearFromTextureMap(m_textureIDList[i]);
  //   }
  // for(unsigned int i = 0; i < m_gameObjects.size(); i++)
  //   {
  //     m_gameObjects[i]->clean();
  //   }
  // m_gameObjects.clear();
    std::cout << "exiting GameOverState\n";
  return true;
}

void GameOverState::render()
{
  for(unsigned int i = 0; i < m_gameObjects.size(); i++)
    {
      m_gameObjects[i]->draw();
    }
}
