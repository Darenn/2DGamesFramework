#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include "SDLGameObject.h"
#include "BaseCreator.h"

class LoaderParams;

/**
   Represent an animated graphic with a speed.
*/
class AnimatedGraphic : public SDLGameObject
{
public:
	void update();
	void load(const LoaderParams *pParams);
	
private:
	int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
		{
			return new AnimatedGraphic();
		}
};

#endif
