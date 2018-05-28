#pragma once
#include <SFML\Graphics.hpp>
#include "Items.h"

class GUISlot {
private:
	bool empty;
	sf::RectangleShape slot;
	Items *slotItem;
public:
	GUISlot();
	~GUISlot();
	void setPosition(int, int);
	void draw();
};

