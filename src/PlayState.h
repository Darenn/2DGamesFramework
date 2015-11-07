#ifndef __PLAYSTATE__
#define __PLAYSTATE__

#include "GameState.h"
#include <vector>

class SDLGameObject;
class Level;

/**
 * State which represented the main part of the game
 * Where the player finaly play 
 */
class PlayState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit() { GameState::onExit(); }
	std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	Level* pLevel;
	
private:
	static const std::string s_playID;
};

#endif
