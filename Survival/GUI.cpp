#include <iostream>
#include "GUI.h"


void GUI::draw(sf::RenderWindow & _window) {
	for (auto& p : panels) {
		if (p.getVisible())
			p.draw(_window);
	}
}

GUI::GUI() {
	panels.emplace_back(GUIPanel(1, sf::Vector2f(0, 0), sf::Vector2f(300, 200), true));
	panels.emplace_back(GUIPanel(2, sf::Vector2f(980, 0), sf::Vector2f(300, 200), true));
	panels.emplace_back(GUIPanel(3, sf::Vector2f(0, 528), sf::Vector2f(1280, 192), true));
}

GUI::~GUI()
{
}
