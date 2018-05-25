#pragma once
#include <SFML\Graphics.hpp>

class GUI  {
protected:
	int GUIid;
	sf::RectangleShape GUIshape;
	bool isVisible;
	//sf::Texture shapeTexture;
public:
	GUI();
	//ID, GUI-POS, GUI-SIZE,  VISIBLE...
	GUI(int, sf::Vector2f, sf::Vector2f, bool);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _newPos);
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow &_window) const = 0;
	virtual ~GUI();
};

class GUIPanel : public GUI {
public:
	void update();
	GUIPanel();
//	//ID, SIZE, VISIBLE...
	GUIPanel(int, sf::Vector2f, sf::Vector2f, bool, sf::Color);
	GUIPanel(int, sf::Vector2f, sf::Vector2f, bool, std::string);
	void draw(sf::RenderWindow &_window) const;
	virtual ~GUIPanel();
};

