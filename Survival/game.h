#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "Text.h"

class Game : public GameState {
private:
	bool startMsg;
public:
	//std::unique_ptr<GUI> ui;
	//std::unique_ptr<GUI> quests;
	//std::unique_ptr<GUI> map;
	//sf::Vector2f Wsize;
	std::vector <std::unique_ptr<Text>> txt;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
	
};
