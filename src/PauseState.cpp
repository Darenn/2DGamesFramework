#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "StateParser.h"
#include<iostream>
#include "GameStateMachine.h"
#include "TextureManager.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
  TheGame::Instance()->getStateMachine()
    ->changeState(new MainMenuState());
}
void PauseState::s_resumePlay()
{
  TheGame::Instance()->getStateMachine()->popState();
}

bool PauseState::onEnter()
{
  StateParser stateParser;
  stateParser.parseState("xml/test.xml", s_pauseID, &m_gameObjects,
			 &m_textureIDList);
  m_callbacks.push_back(0);
  m_callbacks.push_back(s_pauseToMain);
  m_callbacks.push_back(s_resumePlay);
  setCallbacks(m_callbacks);
  std::cerr << "entering PauseState\n";
  return true;
}

// same as MainMenuState
void PauseState::setCallbacks(const std::vector<Callback>&
			      callbacks)
{
  // go through the game objects
  for(int i = 0; i < m_gameObjects.size(); i++)
    {
      // if they are of type MenuButton then assign a callback based
      //on the id passed in from the file
	if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
	  {
	    MenuButton* pButton =
	      dynamic_cast<MenuButton*>(m_gameObjects[i]);
	    pButton->setCallback(callbacks[pButton->getCallbackID()]);
	  }
    }
}
