#ifndef __STATEPARSER__
#define __STATEPARSER__

#include <vector>
#include <string>

class TiXmlElement;
class GameObject;

class StateParser
{
public:
  bool parseState(const char* stateFile, std::string stateID,
		  std::vector<GameObject*> *pObjects,
		  std::vector<std::string> *pTextureIDs);
private:
  void parseObjects(TiXmlElement* pStateRoot,
		    std::vector<GameObject*> *pObjects);
  void parseTextures(TiXmlElement* pStateRoot,
		     std::vector<std::string> *pTextureIDs);
};

#endif
