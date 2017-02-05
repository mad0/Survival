#pragma once
#include <SFML\Graphics.hpp>

class GameState;

class Game {
public:
	sf::RenderWindow okno;
	Game();
	void mainLoop(GameState* state);

	~Game();



};