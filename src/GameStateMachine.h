#ifndef __GAMESTATEMACHINE__
#define __GAMESTATEMACHINE__

#include <vector>
#include "Singleton.h"

class GameState;
/**
 * Handle all states of the game
 */
class GameStateMachine : public Singleton<GameStateMachine>
{
	friend Singleton;
	
public:
// add state without removing the previous state
void pushState(GameState* pState);

// remove the previous state before adding another
void changeState(GameState* pState);

// remove the current state 
void popState();

// update the current state
void update();

// render the current state
void render();

private:
// will store states, the back will contains the current state
std::vector<GameState*> m_gameStates;

};

#endif

