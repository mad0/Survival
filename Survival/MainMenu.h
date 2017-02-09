#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "GameState.h"

class MainMenu : public GameState {
	sf::Text t;
	sf::Font font;
	std::vector<sf::Text> text;
	std::vector<std::string> menu;
public:
	virtual void inputs();
	virtual void update();
	virtual void draw();
	MainMenu(Engine* gra);
	~MainMenu();
};
