#ifndef __BASECREATOR__
#define __BASECREATOR__

class GameObject;

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

#endif
