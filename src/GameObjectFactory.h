#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__

#include <string>
#include <map>
#include "Singleton.h"

class BaseCreator;

class GameObjectFactory : public Singleton<GameObjectFactory>
{
	friend Singleton;
	
public:
	bool registerType(std::string typeID, BaseCreator* pCreator);
	GameObject* create(std::string typeID);

private:
    std::map<std::string, BaseCreator*> m_creators;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif
