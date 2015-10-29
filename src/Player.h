#ifndef __PLAYER__
#define __PLAYER__

#include "GameObject.h"
#include <string>

class Player : public GameObject
{
 public:
  void load(int x, int y, int width, int height, std::string textureID);
  void draw(SDL_Renderer* pRenderer);
  void update();
  void clean(){};
};

#endif
