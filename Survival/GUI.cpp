#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>

//Main GUI texture, rozmiar okna, pozycja, skala
GUI::GUI(const std::string& texture) {
	std::cout << "Tworze GUI...\n";
	GUITexture.loadFromFile("GUI/" + texture + ".png");
	GUISprite.setTexture(GUITexture);
	//sf::Vector2u Tsize = GUITexture.getSize();
	//GUISprite.setScale(Wsize.x/Tsize.x, Wsize.y/Tsize.y);
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//states.transform *= getTransform();
	target.draw(GUISprite);
}

GUI::~GUI(){
	std::cout << "Niszcze GUI...\n";
}
