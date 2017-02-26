#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>

//Main GUI
GUI::GUI() {
	T_bg.loadFromFile("gui.png");
	bg.setTexture(T_bg);
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	std::cout << "dra..\n";
	target.draw(bg);
}


GUI::~GUI()
{
}
