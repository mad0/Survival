#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

class GameState;

class Game {
public:
	std::stack<GameState*> obiekty;
	sf::RenderWindow okno;
	void push(GameState*);
	GameState* pop();
	Game();
	void run();
	~Game();
};