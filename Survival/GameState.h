#pragma once
#include "Game.h"

class GameState {

public:
	Game* game;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};