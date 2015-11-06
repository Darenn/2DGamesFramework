#ifndef __PAUSESTATE__
#define __PAUSESTATE__

#include "MenuState.h"
#include <vector>
#include <string>

class PauseState : public MenuState
{
public:
	virtual void update() { MenuState::update(); }
	virtual void render() { MenuState::render(); }
	bool onEnter();
	virtual bool onExit() { MenuState::onExit(); }
	std::string getStateID() const { return s_pauseID; }
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
};

#endif
