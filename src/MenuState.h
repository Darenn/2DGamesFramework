#ifndef __MENUSTATE__
#define __MENUSTATE__

#include "GameState.h"
#include "GameObject.h"
#include <string>
#include <vector>

class MenuState : public GameState
{
public:
  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();
  virtual std::string getStateID() const { return s_menuID; }
private:
  std::vector<GameObject*> m_gameObjects;
  static const std::string s_menuID;
  // call back functions for menu items
  static void s_menuToPlay();
  static void s_exitFromMenu();
};

#endif
