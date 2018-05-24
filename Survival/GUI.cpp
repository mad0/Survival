#include "GUI.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>

GUI::GUI(int _GUIid,  sf::Vector2f _GUIpos, bool _isVisible) :GUIid(_GUIid), GUIpos(_GUIpos), isVisible(_isVisible) {
	std::cout << "GUI is created.\n";
	GUIshape.setFillColor(sf::Color::Green);
	GUIshape.setPosition(_GUIpos);
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
GUIPanel::GUIPanel(int _GUIid, sf::Vector2f _GUIpos, bool _isVisible, sf::Color _bgColor) : GUI(GUIid, GUIpos, isVisible), bgColor(_bgColor) {
	GUIshape.setFillColor(_bgColor);
	GUIshape.setPosition(_GUIpos);
	GUIshape.setSize(sf::Vector2f(1280, 192));
	panelFont.loadFromFile("fonts/Vecna.otf");
	panelText.setFont(panelFont);
	panelText.setString("Panel 1");
	panelText.setCharacterSize(25);
	panelText.setPosition(GUIshape.getPosition().x+10, GUIshape.getPosition().y);
}

void GUIPanel::draw(sf::RenderWindow & _window) const {
	_window.draw(GUIshape);
	_window.draw(panelText);
}

GUIPanel::~GUIPanel() {
}

void GUIPanel::update() {

}
