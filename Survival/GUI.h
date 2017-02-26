#pragma once
#include <SFML\Graphics.hpp>
class GUI {
private:
	
	
public:
	void draw(sf::RenderWindow& okno);
	GUI(GUIText, GUIShapes);
	~GUI();
};

class GUIShapes {
public:
	sf::Sprite DialogBox;
	sf::Texture DialogBG;
};

class GUIText {
public:
	sf::Text text;
	sf::Font font;
};

