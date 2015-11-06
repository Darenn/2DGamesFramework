#ifndef __MENUSTATE__
#define __MENUSTATE__

#include "GameState.h"
#include <string>
#include <vector>

/**
 * A specific GameState for state of type Menu
 * There are so MenuButtons and functions callback to execute
 * when click on buttons.
 */
class MenuState : public GameState
{
public:
	virtual void update() { GameState::update(); }
	virtual void render() { GameState::render(); }
	virtual bool onEnter() = 0;
	virtual bool onExit() { GameState::onExit(); }
	
protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
	std::vector<Callback> m_callbacks;
};

#endif
