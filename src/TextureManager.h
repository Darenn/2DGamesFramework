#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Singleton.h"

/**
 * Handle all textures of the game and draw them.
 */
class TextureManager  : public Singleton<TextureManager>
{
	friend Singleton;
	
public:  
	~TextureManager() {};

/**
 * Load the image "fileName", and store it in "m_textureMap"
 * "pRenderer" : the renderer of the frame
 */
	bool load(std::string fileName, std::string id,
			  SDL_Renderer* pRenderer);

	/**
	 * Draw the texture "id" on position "x" and "y"
	 */
	void draw(std::string id, int x, int y, int width, int
			  height, SDL_Renderer* pRenderer, 
			  SDL_RendererFlip flip = SDL_FLIP_NONE);

/**
 * Use that for draw a sprite.
 * "width" : the width of one sprite's bloc
 * "heigth" : the heigth of one sprite's bloc
 * "currentFrame" : the bloc to draw
 */
	void drawFrame(std::string id, int x, int y, int width, int
				   height, int currentRow, int currentFrame, SDL_Renderer*
				   pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// contains all textures used by the game
	std::map<std::string, SDL_Texture*> m_textureMap;	
	void clearFromTextureMap(std::string id);

private:
	TextureManager() {}

};

typedef TextureManager TheTextureManager;

#endif
  
