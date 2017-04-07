#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

class GameState;

class Engine {
private:
	std::stack<GameState*> obiekty;
	//sf::Clock clock;
	//sf::Time time;
	//sf::Time speed;
public:
	Engine();

	sf::RenderWindow okno;
	void mainLoop();
	void push(GameState*);
	GameState* stos();
	void del();

	~Engine();
};