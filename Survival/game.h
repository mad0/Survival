#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>

class Game : public GameState {
private:
	sf::Text text;
	sf::Font font;
public:
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
};
