#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <map>

class MainMenu : public GameState {
public:
	/*sf::Text t_menu;
	sf::Font f_menu;
	std::vector <std::string> t_menu;
	*/
	virtual void inputs();
	virtual void update();
	virtual void draw();
	MainMenu();
	~MainMenu();
};
