#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "BaseCreator.h"

class Enemy : public SDLGameObject
{
public:
	Enemy();
	void update();

};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
		{
			return new Enemy();
		}
};

#endif
