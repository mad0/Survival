#pragma once
#include <SFML\Graphics.hpp>
class GUI {
private:
	sf::Text text;
	sf::Font font;
	sf::Sprite DialogBox;
	sf::Texture DialogBG;
public:
	void draw(sf::RenderWindow& okno);
	void Inventory();
	GUI();
	~GUI();

};

