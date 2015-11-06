#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

class LoaderParams;

/**
 * Represent a game object of the game
 */
class GameObject
{
 public:
  virtual void render() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;
  virtual void load(const LoaderParams* pParams)=0;

};

#endif
