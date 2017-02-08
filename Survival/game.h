#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

class GameState;

class Game {
	std::stack<GameState*> obiekty;
public:
	Game();

	sf::RenderWindow okno;
	void mainLoop();
	void push(GameState*);
	GameState* top();
	void del();

	~Game();
};