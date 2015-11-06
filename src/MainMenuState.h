#ifndef __MAINMENUSTATE__
#define __MAINMENUSTATE__

#include <string>
#include <vector>
#include "MenuState.h"

class MainMenuState : public MenuState
{
public:
	bool onEnter();
	std::string getStateID() const { return s_menuID; }
private:
	void setCallbacks(const std::vector<Callback>&
					  callbacks);
// call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
};

#endif
