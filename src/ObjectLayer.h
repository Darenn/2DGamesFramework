#ifndef __OBJECTLAYER__
#define __OBJECTLAYER__

#include "Layer.h"
#include <vector>

class GameObject;

class ObjectLayer : public Layer
{
public:
	virtual void update();
	virtual void render();
	std::vector<GameObject*>* getGameObjects()
		{
			return &m_gameObjects;
		}
private:
	std::vector<GameObject*> m_gameObjects;
};

#endif
