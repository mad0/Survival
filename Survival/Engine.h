#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

class GameState;

class Engine {
private:
	std::stack<GameState*> stos;
	//sf::Clock clock;
	//sf::Time time;
	//sf::Time speed;
public:
	Engine();
	~Engine();
	void mainLoop();
	void setState(GameState*);
	GameState* getState();
	void delState();
	sf::RenderWindow window;
};