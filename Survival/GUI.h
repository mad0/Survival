#pragma once
#include <SFML\Graphics.hpp>

class Shapes {
	Shapes();
	~Shapes();
};

class SStyles {
	SStyles();
	~SStyles()
};


class GUI : public sf::Drawable, public sf::Transformable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	GUI();
	~GUI();
};

