#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <string>

class AnimatedGraphic : public SDLGameObject
{
 public:
  AnimatedGraphic(const LoaderParams* pParams, int animSpeed /* see to replace */);
  virtual void draw();
  virtual void update();
  virtual void clean();
private:
  int m_animSpeed;
};
#endif
