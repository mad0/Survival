#pragma once
#include <SFML\Graphics.hpp>

class GUI : public sf::Drawable, public sf::Transformable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite bg;
	sf::Texture T_bg;
public:
	GUI();
	~GUI();
};


