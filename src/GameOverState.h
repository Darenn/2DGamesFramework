#ifndef __GAMEOVERSTATE__
#define __GAMEOVERSTATE__

#include <vector>
#include <string>
#include "MenuState.h"

class GameOverState : public MenuState
{
public:
	void update() { MenuState::update(); }
	void render() { MenuState::render(); }	
	bool onEnter();
	bool onExit() { MenuState::onExit(); }
	std::string getStateID() const {return s_gameOverID;}
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
};

#endif
