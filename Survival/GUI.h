#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "GUIPanel.h"
#include "GUISlot.h"

class Character;

class GUI {
private:
	sf::Texture bgTexture;
	sf::Texture barTexture;
	Character *p1;
	sf::RectangleShape hpBar;
	sf::RectangleShape hpBG;
	std::vector<std::unique_ptr<GUIPanel>> panels;
public:
	void draw(sf::RenderWindow &_window);
	void drawHP();
	void update();
	GUI(Character *_p1);
	~GUI();
};

