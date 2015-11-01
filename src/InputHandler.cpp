#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_mousePosition(0,0){ // i initialise this because it will be NULL if there is not mousemotion
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
  if (joy < SDL_NumJoysticks()) {
    return m_buttonStates[joy][buttonNumber];
  }
  return false;
}

void InputHandler::initialiseJoysticks()
{
  for(int i = 0; i < 3; i++)
    {
      m_mouseButtonStates.push_back(false);
    }
  if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
  if(SDL_NumJoysticks() > 0)
    {
      for(int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_Joystick* joy = SDL_JoystickOpen(i);
	  if(SDL_JoystickGetAttached(joy))
	    {
	      m_joysticks.push_back(joy);
	      m_joystickValues.push_back(std::make_pair
					 (new Vector2D(0,0),new Vector2D(0,0))); // add our pair
	      std::vector<bool> tempButtons;
	      for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
		{
		  tempButtons.push_back(false);
		}
	    }
	  else
	    {
	      std::cout << SDL_GetError();
	    }
	}
      SDL_JoystickEventState(SDL_ENABLE);
      m_bJoysticksInitialised = true;     
    }
  else
    {
      m_bJoysticksInitialised = false;
    }
  std::cout << "Initialised "<< m_joysticks.size() << "joystick(s)" << std::endl;
}

void InputHandler::clean()
{
  if(m_bJoysticksInitialised)
    {
      for(int i = 0; i < SDL_NumJoysticks(); i++)
	{
	  SDL_JoystickClose(m_joysticks[i]);
	}
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
  if(m_keystates != 0)
    {
      if(m_keystates[key] == 1)
	{
	  return true;
	}
      else
	{
	  return false;
	}
    }
  return false;
}

void InputHandler::onKeyDown() {  
}

void InputHandler::onKeyUp() {}

void InputHandler::onMouseMove(SDL_Event& event) {
  if(event.type == SDL_MOUSEMOTION)
    {
      m_mousePosition.setX(event.motion.x);
      m_mousePosition.setY(event.motion.y);
    }
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
  if(event.type == SDL_MOUSEBUTTONDOWN)
    {
      if(event.button.button == SDL_BUTTON_LEFT)
	{
	  m_mouseButtonStates[LEFT] = true;
	}
      if(event.button.button == SDL_BUTTON_MIDDLE)
	{
	  m_mouseButtonStates[MIDDLE] = true;
	}
      if(event.button.button == SDL_BUTTON_RIGHT)
	{
	  m_mouseButtonStates[RIGHT] = true;
	}
    }
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
  if(event.type == SDL_MOUSEBUTTONUP)
    {
      if(event.button.button == SDL_BUTTON_LEFT)
	{
	  m_mouseButtonStates[LEFT] = false;
	}
      if(event.button.button == SDL_BUTTON_MIDDLE)
	{
	  m_mouseButtonStates[MIDDLE] = false;
	}
      if(event.button.button == SDL_BUTTON_RIGHT)
	{
	  m_mouseButtonStates[RIGHT] = false;
	}
    }
}

void InputHandler::onJoystickAxisMove(SDL_Event& event) {
   if(event.type == SDL_JOYAXISMOTION) // check the type value
	{
	  int whichOne = event.jaxis.which; // get which controller
	  // left stick move left or right
	  if(event.jaxis.axis == 0)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setX(1);
		}
	      else if(event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setX(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].first->setX(0);
		}
	    }
	  // left stick move up or down
	  if(event.jaxis.axis == 1)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setY(1);
		}
	      else if(event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].first->setY(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].first->setY(0);
		}
	    }
	  // right stick move left or right
	  if(event.jaxis.axis == 3)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setX(1);
		}
	      else if(event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setX(-1);
		}
	    }
	  else
	    {
	      m_joystickValues[whichOne].second->setX(0);
	    }

	  // right stick move up or down
	  if(event.jaxis.axis == 4)
	    {
	      if (event.jaxis.value > m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setY(1);
		}
	      else if(event.jaxis.value < -m_joystickDeadZone)
		{
		  m_joystickValues[whichOne].second->setY(-1);
		}
	      else
		{
		  m_joystickValues[whichOne].second->setY(0);
		}
	    }
	}
}

void InputHandler::onJoystickButtonDown(SDL_Event& event) {
  if(event.type == SDL_JOYBUTTONDOWN)
    {
      int whichOne = event.jaxis.which;
      m_buttonStates[whichOne][event.jbutton.button] = true;
    }
}

void InputHandler::onJoystickButtonUp(SDL_Event& event) {
  if(event.type == SDL_JOYBUTTONUP)
    {
      int whichOne = event.jaxis.which;
      m_buttonStates[whichOne][event.jbutton.button] = false;
    }
}

void InputHandler::update()
{
  m_keystates = (Uint8*) SDL_GetKeyboardState(0);
  SDL_Event event;
  while(SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  TheGame::Instance()->quit();
	  break;
	case SDL_JOYAXISMOTION:
	  onJoystickAxisMove(event);
	  break;
	case SDL_JOYBUTTONDOWN:
	  onJoystickButtonDown(event);
	  break;
	case SDL_JOYBUTTONUP:
	  onJoystickButtonUp(event);
	  break;
	case SDL_MOUSEMOTION:
	  onMouseMove(event);
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  onMouseButtonDown(event);
	  break;
	case SDL_MOUSEBUTTONUP:
	  onMouseButtonUp(event);
	  break;
	case SDL_KEYDOWN:
	  onKeyDown();
	  break;
	case SDL_KEYUP:
	  onKeyUp();
	  break;
	default:
	  break;
	}
    }
}

int InputHandler::xvalue(int joy, int stick)
{
  if(m_joystickValues.size() > 0)
    {
      if(stick == 1)
	{
	  return m_joystickValues[joy].first->getX();
	}
      else if(stick == 2)
	{
	  return m_joystickValues[joy].second->getX();
	}
    }
  return 0;
}
int InputHandler::yvalue(int joy, int stick)
{
  if(m_joystickValues.size() > 0)
    {
      if(stick == 1)
	{
	  return m_joystickValues[joy].first->getY();
	}
      else if(stick == 2)
	{
	  return m_joystickValues[joy].second->getY();
	}
    }
  return 0;
}

void InputHandler::reset()
{
  for( int i = 0; i < m_mouseButtonStates.size(); i++)
    m_mouseButtonStates[i] = false;
}
