#pragma once
#include "GameState.h"
#include "GUI.h"
#include <SFML\Graphics.hpp>

class Game : public GameState {
private:
	
public:
	bool inv = false;
	GUI gui;
	static int num;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
};
