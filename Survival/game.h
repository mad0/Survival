#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "Map.h"
#include "Player.h"

class Game : public GameState {
private:
	bool startMsg;
	sf::Text gui[2];
	std::string guiStr[2];
	sf::Font font;
public:
	Player p1;
	//Map map1;
	//std::unique_ptr<GUI> ui;
	//std::unique_ptr<GUI> quests;
	//std::unique_ptr<GUI> map;
	//sf::Vector2f Wsize;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
	
};
