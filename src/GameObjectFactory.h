#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__

#include <string>
#include <map>
#include "BaseCreator.h"

class GameObjectFactory
{
public:
  bool registerType(std::string typeID, BaseCreator* pCreator);
  GameObject* create(std::string typeID);
  static GameObjectFactory* Instance()
  {
    if(s_pInstance == 0)
      {
	s_pInstance = new GameObjectFactory();
      }
    return s_pInstance;
  };

private:
    std::map<std::string, BaseCreator*> m_creators;
   static GameObjectFactory* s_pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif
