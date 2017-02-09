#include <iostream>
#include "GameState.h"
#include "Engine.h"
#include "Game.h"

Engine::Engine() {
	okno.create(sf::VideoMode(1440, 800), "Syrvival - Alpha");
	okno.setFramerateLimit(60);
	okno.setVerticalSyncEnabled(true);
}

void Engine::mainLoop() {
		obiekty.top()->main();
		del();
}


void Engine::push(GameState* stan) {
	obiekty.push(stan);
}

GameState* Engine::top() {
		return obiekty.top();
}

void Engine::del() {
	delete obiekty.top();
	obiekty.pop();
}
 
Engine::~Engine() {
	std::cout << "Zamykam GRE\n";
}