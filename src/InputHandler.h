#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
#include <utility>

enum mouse_buttons
  {
LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
  };


class InputHandler
{
public:
const int m_joystickDeadZone = 10000;
static InputHandler* Instance()
{
if(s_pInstance == 0)
  {
s_pInstance = new InputHandler();
}
return s_pInstance;
};
void update();
void clean();
void initialiseJoysticks();
bool joysticksInitialised() {
return m_bJoysticksInitialised; };
std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
int xvalue(int joy, int stick);
int yvalue(int joy, int stick);
std::vector<std::vector<bool>> m_buttonStates;
bool getButtonState(int joy, int buttonNumber);
std::vector<bool> m_mouseButtonStates;
bool getMouseButtonState(int buttonNumber)
{
return m_mouseButtonStates[buttonNumber];
}
Vector2D* getMousePosition()
{
return &m_mousePosition;
}
Uint8* m_keystates;
bool isKeyDown(SDL_Scancode key);
private:
Vector2D m_mousePosition;
InputHandler();
~InputHandler() {};
static InputHandler* s_pInstance;
std::vector<SDL_Joystick*> m_joysticks;
bool m_bJoysticksInitialised;

// private functions to handle different event types
// handle keyboard events
void onKeyDown();
void onKeyUp();
// handle mouse events
void onMouseMove(SDL_Event& event);
void onMouseButtonDown(SDL_Event& event);
void onMouseButtonUp(SDL_Event& event);
// handle joysticks events
void onJoystickAxisMove(SDL_Event& event);
void onJoystickButtonDown(SDL_Event& event);
void onJoystickButtonUp(SDL_Event& event);
};
typedef InputHandler TheInputHandler;

#endif
