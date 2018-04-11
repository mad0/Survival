#pragma once
#include <SFML\Graphics.hpp>
#include "Engine.h"

class GameState {
	
public:
	virtual void inputs() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual  ~GameState() = 0;
protected:
	Engine *engine;
	GameState();
};
