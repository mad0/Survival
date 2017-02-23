#pragma once
#include <SFML\Graphics.hpp>

class Items {

public:
	sf::Text text;
	sf::Font font;
	sf::Sprite DialogBox;
	sf::Texture DialogBG;
	static bool InvPressed;
	void Inventory();
	Items();
	~Items();
};
