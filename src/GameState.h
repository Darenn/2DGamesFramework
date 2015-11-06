#ifndef __GAMESTATE__
#define __GAMESTATE__

#include <string>
#include <vector>

class GameObject;

class GameState
{
public:
  virtual void update();
  virtual void render();
  virtual bool onEnter() = 0;
  virtual bool onExit();
  virtual std::string getStateID() const = 0;

protected:
	std::vector<std::string> m_textureIDList;
	std::vector<GameObject*> m_gameObjects;

};

#endif
