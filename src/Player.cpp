#include "Player.h"

Player::Player(const LoaderParams* pParams) :
  SDLGameObject(pParams)
{
}
void Player::draw()
{
  SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
  handleInput(); // add our function
  SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
      m_velocity.setX(1);
    }      
  if(TheInputHandler::Instance()->getButtonState(0, 3))
    {
      std::cout << "passe fans le if" << std::endl;
      m_velocity.setX(1);
    }
  if(TheInputHandler::Instance()->joysticksInitialised())
    {
      if(TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
	 TheInputHandler::Instance()->xvalue(0, 1) < 0)
	{
	  m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,1));
	}
      if(TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
	 TheInputHandler::Instance()->yvalue(0, 1) < 0)
	{
	  m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,1));
	}
      if(TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
	 TheInputHandler::Instance()->xvalue(0, 2) < 0)
	{
	  m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,2));
	}
      if(TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
	 TheInputHandler::Instance()->yvalue(0, 2) < 0)
	{
	  m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,2));
	}
    }
}
