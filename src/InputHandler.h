#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include <vector>
#include "Vector2D.h"
#include <utility>
#include "Singleton.h"
#include "SDL2/SDL.h"

/**
 * A value for each mouse's buttons.
 */
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

/**
 * Handle all events made by user (mouse, keyboard, joystick)
 */
class InputHandler : public Singleton<InputHandler>
{
	friend class Singleton; // to access private constructor
	
public:
	const int m_joystickDeadZone = 10000;

/**
 * Handle all events sent by SDL.
 */
	void update();
	
	/**
	 * Clean the class by close joysticks
	 */
	void clean();	
	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }

	/**
	 * Contains for each joystick a pair of Vector2D
	 * which represent the movement of both
	 * analog stick of the joystick.
	 */
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	
	/**
	 * Get the x value of joystick'stick given.
	 */
	int xvalue(int joy, int stick);

	/**
	 * Get the y value of joystick'stick given.
	 */
	int yvalue(int joy, int stick);

	/**
	 * Each vector contained,
	 * contains a boolean value for each joystick's button.
	 * The boolean is true if the button is pressed.
	 */
	std::vector<std::vector<bool>> m_buttonStates;
	
	/**
	 * Return true if the "buttonNumber" button of "joy" is pressed.
	 */
	bool getButtonState(int joy, int buttonNumber);

	/**
	 * Contains a boolean for each mouse's button.
	 * The boolean is true is the button is pressed.
	 */
	std::vector<bool> m_mouseButtonStates;

	/**
	 * Return true if the "buttonNumber" mouse's button is pressed.
	 */
	bool getMouseButtonState(int buttonNumber)
		{
			return m_mouseButtonStates[buttonNumber];
		}
	
	Vector2D* getMousePosition()
		{
			return &m_mousePosition;
		}
	
	/**
	 * Contains the state of all keyboard's keys.
	 */
	Uint8* m_keystates;
	bool isKeyDown(SDL_Scancode key);
	/**
	 * Reset all mouse's buttons to non-pressed (false).
	 */
	void reset();

private:
	InputHandler(){};
	Vector2D m_mousePosition;
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
