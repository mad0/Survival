#pragma once
#include "GameState.h"
#include "Items.h"
#include "Quests.h"
#include <SFML\Graphics.hpp>

class Game : public GameState {
private:
	
public:
	static int num;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
};
