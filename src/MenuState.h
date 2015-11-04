#ifndef __MENUSTATE__
#define __MENUSTATE__

#include "GameState.h"
#include "GameObject.h"
#include <string>
#include <vector>


class MenuState : public GameState
{
protected:
typedef void(*Callback)();
virtual void setCallbacks(const std::vector<Callback>& callbacks)
= 0;
std::vector<Callback> m_callbacks;
};

#endif
