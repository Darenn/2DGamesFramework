#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include <string>
#include "LoaderParams.h"
#include "BaseCreator.h"

class Player : public SDLGameObject
{
 public:
  Player();
  virtual void draw();
  virtual void update();
  virtual void clean();
  
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
