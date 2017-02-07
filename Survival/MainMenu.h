#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"


class MainMenu : public GameState {
public:
	sf::Text text;
	sf::Font font;


	virtual void input();
	virtual void update();
	virtual void draw();
	MainMenu(Game* gra);

};
