#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <string>
#include "BaseCreator.h"

class Enemy : public SDLGameObject
{
 public:
  Enemy();
  virtual void draw();
  virtual void update();
  virtual void clean();  
};

class EnemyCreator : public BaseCreator
{
  GameObject* createGameObject() const
  {
    return new Enemy();
  }
};

#endif
