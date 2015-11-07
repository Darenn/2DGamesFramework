#include "PlayState.h"
#include "Game.h"
#include <iostream>
#include "PauseState.h"
#include "SDLGameObject.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "Level.h"
#include "LevelParser.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::render()
{
	GameState::render();
	pLevel->render();
}

void PlayState::update()
{
	
	GameState::update();
	pLevel->update();
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
		TheGame::Instance()->getStateMachine()
	->pushState(new PauseState());
    }
  // problem here if no object
  /*if(checkCollision(dynamic_cast<SDLGameObject*>
		    (m_gameObjects[0]), dynamic_cast<SDLGameObject*>
		    (m_gameObjects[1])))
    {
      TheGame::Instance()->getStateMachine()
	->pushState(new GameOverState());
    }*/
}

bool PlayState::onEnter()
{
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("assets/map1.tmx");
	StateParser stateParser;
	stateParser.parseState("xml/test.xml", s_playID, &m_gameObjects,
	&m_textureIDList);
	std::cout << "entering PlayState\n";
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
