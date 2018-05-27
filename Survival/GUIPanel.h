#pragma once
#include "SFML\Graphics.hpp"

class GUIPanel {
private:
	int id;
	sf::RectangleShape GUIshape;
	bool isVisible;
	sf::Texture shapeTexture;
public:
	GUIPanel();
	//ID, GUI-POS, GUI-SIZE,  VISIBLE...
	GUIPanel(int, sf::Vector2f, sf::Vector2f, bool);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _newPos);
	void setVisible(bool);
	bool getVisible();
	void setTexture(std::string _textureFile);
	void setColor(sf::Color);
	void setSlots();
	void update();
	void draw(sf::RenderWindow &_window);
	~GUIPanel();
};
