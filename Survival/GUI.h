#pragma once
#include <SFML\Graphics.hpp>
#include "GUIPanel.h"

class GUI {
private:
	std::vector<GUIPanel> panels;
public:
	void draw(sf::RenderWindow &_window);
	GUI();
	~GUI();
};

