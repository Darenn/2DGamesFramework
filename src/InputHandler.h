#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
#include <utility>

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
private:
InputHandler() {};
~InputHandler() {};
static InputHandler* s_pInstance;
std::vector<SDL_Joystick*> m_joysticks;
bool m_bJoysticksInitialised;
};
typedef InputHandler TheInputHandler;

#endif
