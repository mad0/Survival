#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

class GameState;

class Engine {
	std::stack<GameState*> obiekty;
public:
	Engine();

	sf::RenderWindow okno;
	void mainLoop();
	void push(GameState*);
	GameState* top();
	void del();

	~Engine();
};