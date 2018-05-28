#include "GUISlot.h"

GUISlot::GUISlot() {
	std::cout << "Tworze slot...\n";
	slotItem = nullptr;
	empty = true;
	slot.setFillColor(sf::Color::Green);
	slot.setSize(sf::Vector2f(62, 64));
}

GUISlot::~GUISlot() {
	//delete slotItem;
}

void GUISlot::setPosition(int _x, int _y) {
	slot.setPosition(_x, _y);
}

void GUISlot::draw(){
	
}
