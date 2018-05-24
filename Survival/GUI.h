#pragma once
#include <SFML\Graphics.hpp>

class GUI  {
protected:
	int GUIid;
	sf::RectangleShape GUIshape;
	sf::Texture *GUItexture;
	std::string GUItexturename;
	sf::Vector2f GUIpos;
	//std::string GUItextstring;
	//sf::Text GUItext;
	//sf::Font GUIfont;
	//sf::Vector2f GUItextpos;
	//sf::Color GUItextcolor;
	bool isVisible;
public:
	GUI(int _GUIid, std::string _GUItexturename, sf::Vector2f _GUIpos, bool _isVisable);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _newPos);
	void update();
	void draw(sf::RenderWindow &_window) const;
	~GUI();
};

class GUIPanel : public GUI {
	void update();
	GUIPanel();
	~GUIPanel();
};

