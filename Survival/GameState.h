#pragma once
#include "Game.h"

class GameState {
public:
	Game* gra;
	virtual void inputs()=0;
	virtual void update()=0;
	virtual void draw()=0;
};