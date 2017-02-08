#pragma once
#include "Game.h"

class GameState {
	
public:

	Game* gameStatePTR;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual  ~GameState() = 0;
protected:
	GameState();
	
	
};
