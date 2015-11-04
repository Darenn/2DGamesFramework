#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <string>
#include "BaseCreator.h"

class AnimatedGraphic : public SDLGameObject
{
 public:
  AnimatedGraphic();
  virtual void draw();
  virtual void update();
  virtual void clean();
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
