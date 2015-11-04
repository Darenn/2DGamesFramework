#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "BaseCreator.h"
#include "GameObject.h"

class MenuButton : public SDLGameObject
{
public:
  MenuButton();
  virtual void draw();
  virtual void update();
  virtual void clean();
  void (*m_callback)();
  void load(const LoaderParams *pParams);
  bool m_bReleased;
  void setCallback(void(*callback)()) { m_callback = callback;};
  int getCallbackID() { return m_callbackID; };

private:
  enum button_state
    {
      MOUSE_OUT = 0,
      MOUSE_OVER = 1,
      CLICKED = 2
    };
  int m_callbackID;
};

class MenuButtonCreator : public BaseCreator
{
  GameObject* createGameObject() const
  {
    return new MenuButton();
  }
};

#endif
