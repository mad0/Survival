#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>

//Main GUI
GUI::GUI(const std::string& texture, sf::Vector2f Wsize) : Wsize(Wsize){
	std::cout << "Tworze GUI...\n";
	file.insert(std::make_pair(texture, "GUI/"+texture+".png"));
	GUITexture.loadFromFile(file[texture]);
	GUISprite.setTexture(GUITexture);
	sf::Vector2u Tsize = GUITexture.getSize();
	GUISprite.setScale(Wsize.x/Tsize.x, Wsize.y/Tsize.y);
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	//states.transform *= getTransform();
	target.draw(GUISprite);
}

GUI::~GUI(){
	std::cout << "Niszcze GUI...\n";
}
