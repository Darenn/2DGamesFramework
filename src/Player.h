#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include "BaseCreator.h"

class Player : public SDLGameObject
{
public:
	void update();
  
private:
	void handleInput();
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
		{
			return new Player();
		}
};

#endif
