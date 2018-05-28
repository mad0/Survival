
#include <iostream>
#include "GUIPanel.h"

GUIPanel::GUIPanel(int _GUIid, sf::Vector2f _GUIpos, sf::Vector2f _GUIsize, bool _isVisible) : id(_GUIid), isVisible(_isVisible) {
	std::cout << "TWORZE GUI PANEL...\n";

	GUIshape.setPosition(_GUIpos);
	GUIshape.setSize(sf::Vector2f(_GUIsize));
}

sf::Vector2f GUIPanel::getPosition() {
	return GUIshape.getPosition();
}

void GUIPanel::setPosition(sf::Vector2f _newPos) {
	GUIshape.setPosition(_newPos);
}

void GUIPanel::setVisible(bool _isVisible) {
	isVisible = _isVisible;
}

bool GUIPanel::getVisible() {
	return isVisible;
}


void GUIPanel::setTexture(std::string _textureFile) {
	shapeTexture.loadFromFile(_textureFile);
	GUIshape.setTexture(&shapeTexture);
}

void GUIPanel::setColor(sf::Color _color) {
	GUIshape.setFillColor(_color);
}

void GUIPanel::setSlots() {
}

sf::FloatRect GUIPanel::mouseOverSlot() {
	return GUIshape.getGlobalBounds();
}


void GUIPanel::draw(sf::RenderWindow & _window) {
	if (isVisible)
		_window.draw(GUIshape);
}

GUIPanel::~GUIPanel() {
	std::cout << "Niszcze GUI...\n";
}

