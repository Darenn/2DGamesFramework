#ifndef __LEVELPARSER__
#define __LEVELPARSER__

#include <vector>
#include "Level.h" // for struct tileset

class Layer;
class TiXmlElement;

class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);   
	
private:
	void parseTilesets(TiXmlElement* pTilesetRoot,
					   std::vector<Tileset>* pTilesets);
	
	void parseTileLayer(TiXmlElement* pTileElement,
						std::vector<Layer*> *pLayers,
						const std::vector<Tileset>* pTilesets);
	void parseTextures(TiXmlElement* pTextureRoot);
	
	void parseObjectLayer(TiXmlElement* pObjectElement,
						  std::vector<Layer*> *pLayers);
	
	int m_tileSize;
	int m_width;
	int m_height;
};

#endif
