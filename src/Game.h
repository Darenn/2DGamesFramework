#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Singleton.h"

class GameObject;
class GameStateMachine;


/**
 *Represent the unique instance of the game (singleton).
 *It will manage all aspects of the game.
 *As a singleton you should refer to it with TheGame
 */
class Game : public Singleton<Game>
{
	friend class Singleton;
public:
	
	/**
	 * Initialize the game (create the window)
	 * title : frame's title
	 * posx : x position of the frame on the screen
	 * posy : y position of the frame on the screen
	 * width : frame's width
	 * height : frame's height
	 * fullscreen : set to true to have the frame in fullscreen
	 */	
	bool init(const char* title, int posx, int posy, int width, int height, bool fullscreen);

	/**
	 * Handle all events on the frame
	 */
	void handleEvents();
	
	/**
	 * Update all the game objects of the game
	 */	
	void update();
	
	/**
	 * Render all the game objects on the frame
	*/
	void render();

	/**
	 * Return true if the game is over
	 */
	bool running() { return m_bRunning; }

	/**
	 * Indicate that the game is over by using m_bRunning
	 */
	void quit() { m_bRunning = false; }

	/**
	 * Clean the frame and the game
	 * You should call it before quit
	*/
	void clean();	

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
  
private:

	//static Game* s_pInstance; // the unique instance of game
	bool m_bRunning; // set to true is the game is running
	SDL_Window* m_pWindow; // windows of the game
	SDL_Renderer* m_pRenderer; // renderer of the frame
	GameStateMachine* m_pGameStateMachine; // the gameStateMachine of the game

protected:
	
	/**
	 * Private constructor for singleton
	 */
	Game() {};

};

// to show it's a singleton
typedef Game TheGame;


#endif
