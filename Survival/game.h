#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "Map.h"
#include "Character.h"

class Game : public GameState {
private:
	bool startMsg;
	sf::Text gui[4];
	std::string guiStr[4];
	sf::Font font;
	sf::Vector2f Wsize;
public:
	std::unique_ptr<Character> p1;
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
