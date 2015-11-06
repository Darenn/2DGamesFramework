#include "AnimatedGraphic.h"
#include "SDLGameObject.h"
#include "SDL2/SDL.h"
#include "LoaderParams.h"

void AnimatedGraphic::update()
{
  m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %
			m_numFrames));
  SDLGameObject::update();
}

void AnimatedGraphic::load(const LoaderParams *pParams)
{
  SDLGameObject::load(pParams);
  m_animSpeed = pParams->getAnimSpeed();
}

