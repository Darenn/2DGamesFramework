#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "GameStateMachine.h"


/**
 *Represent an instance of the game.
 *It will manage all aspects of the game.
 *As a singleton you should refer to it with TheGame
 */
class Game
{ 
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
	   Render all the game objects on the frame
	*/
	void render();
	/**
	   Update all the game objects of the game
	*/
	void update();
	/**
	   Handle all events on the frame
	*/
	void handleEvents();
	/**
	   Clean the frame and the game
	   You should call it before quit
	*/
	void clean();
	/**
	   Indicate that the game is over by using m_bRunning
	*/
	void quit() { m_bRunning = false; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	/**
	   Return true is the is over
	*/
	bool running() { return m_bRunning; }
		
	int m_currentFrame;  
	std::vector<GameObject*> m_gameObjects;

	static Game* Instance()
		{
			if(s_pInstance == 0)
			{
				s_pInstance = new Game();
				return s_pInstance;
			}
			return s_pInstance;
		}
	GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
  
private:
  
	void draw();
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	Game() {};
	static Game* s_pInstance;
	GameStateMachine* m_pGameStateMachine;
  
};

typedef Game TheGame;

#endif
