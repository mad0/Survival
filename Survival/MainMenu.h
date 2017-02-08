#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "GameState.h"

class MainMenu : public GameState {
	sf::Text text;
	sf::Font font;
	std::vector <std::string>menu;
public:
	virtual void input();
	virtual void update();
	virtual void draw();
	MainMenu(Game* gra);
	~MainMenu();
};
