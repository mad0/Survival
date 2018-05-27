#include <iostream>
#include "GUI.h"


void GUI::draw(sf::RenderWindow & _window) {
	for (auto& p : panels) {
		if (p->getVisible())
			p->draw(_window);
	}
	for (auto& s : slots) {
		if (s->getVisible())
			s->draw(_window);
	}
}

GUI::GUI() {
	std::cout << "TWORZE GUI....\n";
	//panels.emplace_back(new GUIPanel(1, sf::Vector2f(0, 0), sf::Vector2f(300, 200), true));
	//panels.emplace_back(new GUIPanel(2, sf::Vector2f(980, 0), sf::Vector2f(300, 200), true));
	//panels.emplace_back(new GUIPanel(3, sf::Vector2f(0, 528), sf::Vector2f(1280, 192), true));
	for (auto& p : panels)
		p->setColor(sf::Color(48, 34, 6, 255));
	for (int x=0;x<6;x++)
	//	slots.emplace_back(new GUIPanel(x, sf::Vector2f(10+(x*74), 538), sf::Vector2f(64, 64), true));
	for (auto& s : slots)
		s->setColor(sf::Color(255, 0, 0, 150));
		
}

GUI::~GUI() {
}
