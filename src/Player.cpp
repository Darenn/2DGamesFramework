#include "Player.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "SDLGameObject.h"
#include "SDL2/SDL.h"

void Player::update()
{
  // to modify because 5 is the number of pictures
  m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
  handleInput(); // add our function
  SDLGameObject::update();
}

void Player::handleInput()
{
  
  Vector2D* target = TheInputHandler::Instance()
    ->getMousePosition();
  m_velocity = *target - m_position;
  m_velocity /= 50;
}
