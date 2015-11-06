#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__

#include "GameObject.h"
#include <string>
#include "Vector2D.h"

class LoaderParams;

/**
 * Represent an object drawable with SDL
 */
class SDLGameObject : public GameObject
{
public:
	SDLGameObject(){};
	void render();
	void update();
	void clean() {};
	void load(const LoaderParams* pParams);
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow; // current row on the sprite
	int m_currentFrame; // current "bloc" on the sprite
	int m_numFrames; // number of "bloc" ont eh sprite
	std::string m_textureID; // the texture of this object
};

#endif
