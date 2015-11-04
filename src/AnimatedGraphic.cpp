#include "AnimatedGraphic.h"
#include "SDLGameObject.h"


AnimatedGraphic::AnimatedGraphic()
{
}

void AnimatedGraphic::draw()
{
  SDLGameObject::draw(); // we now use SDLGameObject
}
void AnimatedGraphic::update()
{
  //  std::cout << "speed" << m_animSpeed << " numberFrames" << m_numberFrames << std::endl;
  m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %
			m_numFrames));
  SDLGameObject::update();
}
void AnimatedGraphic::clean()
{
}

void AnimatedGraphic::load(const LoaderParams *pParams)
{
  SDLGameObject::load(pParams);
  m_animSpeed = pParams->getAnimSpeed();
}

