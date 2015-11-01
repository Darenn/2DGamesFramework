#ifndef __GAMESTATE__
#define __GAMESTATE__

#include<string>

class GameState
{
public:
  // same goal as the game's functions
  virtual void update() = 0;
  virtual void render() = 0;

  // the state is created
  virtual bool onEnter() = 0;
  // the state is removed
  virtual bool onExit() = 0;

  // An id for the state
  virtual std::string getStateID() const = 0;
};

#endif
