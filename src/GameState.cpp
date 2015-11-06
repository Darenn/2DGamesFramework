#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"

bool GameState::onExit()
{
	for (GameObject* go : m_gameObjects)
		go->clean();
	m_gameObjects.clear();
	// clear the texture manager
	for(int i = 0; i < m_textureIDList.size(); i++)
		TheTextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	return true;
}

void GameState::render()
{
	for(GameObject* go : m_gameObjects)
		go->render();
}

void GameState::update()
{
	for(GameObject* go : m_gameObjects)
		go->update();
}
