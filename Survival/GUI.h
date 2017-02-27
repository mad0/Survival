#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class GUI : public sf::Drawable, public sf::Transformable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f Wsize;
	sf::Sprite GUISprite;
	sf::Texture GUITexture;
	std::map <std::string, std::string> file;
public:
	GUI(const std::string&, sf::Vector2f);
	~GUI();
};


