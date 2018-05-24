#pragma once
#include <SFML\Graphics.hpp>

class GUI  {
public:
	int GUIid;
	sf::RectangleShape GUIshape;
	sf::Vector2f GUIpos;
	bool isVisible;
public:
	GUI(int _GUIid, sf::Vector2f _GUIpos, bool _isVisable);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _newPos);
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow &_window) const = 0;
	virtual ~GUI();
};

class GUIPanel : public GUI {
private:
	sf::Color bgColor;
	sf::Text panelText;
	sf::Font panelFont;
	std::string panelString;
public:
	void update();
	GUIPanel(int _GUIid, sf::Vector2f _GUIpos, bool _isVisible, sf::Color _bgColor);
	void draw(sf::RenderWindow &_window) const;
	virtual ~GUIPanel();
};

