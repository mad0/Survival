#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>

GUI::GUI(int _GUIid, std::string _GUItexturename, sf::Vector2f _GUIpos, bool _isVisible) :
	GUIid(_GUIid),
	GUItexturename(_GUItexturename),
	GUIpos(_GUIpos),
	//GUItextstring(_GUItextstring),
	//GUItextpos(_GUItextpos),
	//GUItextcolor(_GUItextcolor),
	isVisible(_isVisible)
{
	//GUItexture->loadFromFile(GUItexturename);
	//GUIshape.setTexture(&GUItexture);
	GUIshape.setFillColor(sf::Color::Green);
	GUIshape.setPosition(_GUIpos);
}

sf::Vector2f GUI::getPosition() {
	return GUIshape.getPosition();;
}

void GUI::setPosition(sf::Vector2f _newPos) {
	GUIshape.setPosition(_newPos);
}

void GUI::update()
{
}

void GUI::draw(sf::RenderWindow &_window) const {
	_window.draw(GUIshape);

}

GUI::~GUI(){
	std::cout << "Niszcze GUI...\n";
}

//PANEL..........................
GUIPanel::GUIPanel() : GUI(GUIid, GUItexturename, GUIpos, isVisible) {

}

GUIPanel::~GUIPanel() {
}

void GUIPanel::update() {

}