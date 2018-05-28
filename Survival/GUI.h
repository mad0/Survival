#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "GUIPanel.h"
#include "GUISlot.h"

class GUI {
private:
	std::vector<std::unique_ptr<GUIPanel>> panels;
	//std::vector<std::unique_ptr<GUIPanel>> slots;
	std::vector<GUISlot*> slots;
public:
	void draw(sf::RenderWindow &_window);
	void update();
	GUI();
	~GUI();
};

