#pragma once
#include "GameState.h"
#include "GUI.h"
#include <SFML\Graphics.hpp>
#include <memory>

class Game : public GameState {
private:
	
public:
	std::unique_ptr<GUI> ui;
	std::unique_ptr<GUI> quests;
	std::unique_ptr<GUI> map;
	sf::Vector2f Wsize;
	static int num;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
	
};
