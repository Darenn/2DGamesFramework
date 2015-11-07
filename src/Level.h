#ifndef __LEVEL__
#define __LEVEL__

#include <string>
#include <vector>

class LevelParser;
class Layer;

/**
 * Contains all informations about a tileset
 */
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};


class Level
{
public:
	~Level() {}
	void update();
	void render();
	std::vector<Tileset>* getTilesets()
		{
			return &m_tilesets;
		}
	std::vector<Layer*>* getLayers()
		{
			return &m_layers;
		}

private:
	// to make sure the level is parsed before create
	Level(){};
	friend LevelParser;
	
	std::vector<Layer*> m_layers;
	std::vector<Tileset> m_tilesets;
};

#endif
