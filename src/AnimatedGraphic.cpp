#include "AnimatedGraphic.h"


AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) :
  SDLGameObject(pParams), m_animSpeed(animSpeed)
{
}

void AnimatedGraphic::draw()
{
  SDLGameObject::draw(); // we now use SDLGameObject
}
void AnimatedGraphic::update()
{
  m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %
			m_numberFrames));
  SDLGameObject::update();
}
void AnimatedGraphic::clean()
{
}
