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
  // to modify because 5 is the number of pictures
  m_currentFrame = int(((SDL_GetTicks() / 100) % m_numberFrames));
  handleInput(); // add our function
  SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
  
  Vector2D* target = TheInputHandler::Instance()
    ->getMousePosition();
  m_velocity = *target - m_position;
  m_velocity /= 50;
  /*Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
      m_velocity.setX(1);
    }      
  if(TheInputHandler::Instance()->getButtonState(0, 3))
    {
      std::cout << "passe fans le if" << std::endl;
      m_velocity.setX(1);
      }*/

  // test keyboard
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
      m_velocity.setX(2);
    }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
      m_velocity.setX(-2);
    }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
      m_velocity.setY(-2);
    }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
      m_velocity.setY(2);
    }

  // test joystick
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
