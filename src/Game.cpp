#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "GameObjectFactory.h"
#include "AnimatedGraphic.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "TextureManager.h"
#include <iostream>


//Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int posx, int posy,
				int width, int height, bool fullscreen)
{
	int flags(0);
	if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; } 
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cerr << "SDL_Init succeeded" << std::endl;
		m_pWindow = SDL_CreateWindow(title, posx, posy,
									 width, height, flags);
		if (m_pWindow != 0) 
		{
			std::cerr << "SDL_CreateWindow succeeded" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				std::cerr << "SDL_CreateRenderer succeeded" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer,
									   0,0 , 0,255);
			}
			else
			{
				std::cerr << "SDL_CreateRenderer fail" << std::endl;
				return false;
			}
		}
		else 
		{
			std::cerr << "SDL_CreateWindow fail" << std::endl;
			return false;
		}	    
	}
	else
	{
		std::cerr << "SDL_Init fail" << std::endl;
		return false;
	}
	std::cerr << "Init succeeded" << std::endl;

// Test area
	TheTextureManager::Instance()
		->load("assets/animate-alpha.png", "animate", m_pRenderer);  
	TheInputHandler::Instance()
		->initialiseJoysticks();
	TheGameObjectFactory::Instance()
		->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
	TheGameObjectFactory::Instance()
		->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()
		->registerType("Enemy", new EnemyCreator());
	TheGameObjectFactory::Instance()
		->registerType("MenuButton", new MenuButtonCreator());
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());
	m_bRunning = true;
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cerr << "Cleaning game" << std::endl;
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::update()
{
	m_pGameStateMachine->update();
}

/*Game* Game::Instance()
{
	if(s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;			
	}*/

