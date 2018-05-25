#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>

GUI::GUI() {

}

GUI::GUI(int _GUIid, sf::Vector2f _GUIpos, sf::Vector2f _GUIsize, bool _isVisible) :GUIid(_GUIid), isVisible(_isVisible) {
	GUIshape.setPosition(_GUIpos);
	GUIshape.setSize(sf::Vector2f(_GUIsize));
}

sf::Vector2f GUI::getPosition() {
	return GUIshape.getPosition();;
}

void GUI::setPosition(sf::Vector2f _newPos) {
	GUIshape.setPosition(_newPos);
}


GUI::~GUI(){
	std::cout << "Niszcze GUI...\n";
}

//PANEL..........................
GUIPanel::GUIPanel(int _GUIid, sf::Vector2f _GUIpos, sf::Vector2f _GUIsize, bool _isVisible, sf::Color _bgColor) : GUI(_GUIid, _GUIpos, _GUIsize, _isVisible) {
	std::cout << "isVisible: "<<isVisible<< "\n";
	GUIshape.setFillColor(_bgColor);
}

GUIPanel::GUIPanel(int _GUIid, sf::Vector2f _GUIpos, sf::Vector2f _GUIsize, bool _isVisible, std::string _textureFile) : GUI(_GUIid, _GUIpos, _GUIsize, _isVisible) {
	sf::Texture shapeTexture;
	shapeTexture.loadFromFile(_textureFile);
	GUIshape.setTexture(&shapeTexture);
}

void GUIPanel::draw(sf::RenderWindow & _window) const {
	if (isVisible) {
		_window.draw(GUIshape);
	}
}

GUIPanel::~GUIPanel() {
}

void GUIPanel::update() {

}
