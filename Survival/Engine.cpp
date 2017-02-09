#include <iostream>
#include "GameState.h"
#include "Engine.h"

Engine::Engine() {
	okno.create(sf::VideoMode(1440, 800), "Syrvival - Alpha");
	okno.setFramerateLimit(60);
	okno.setVerticalSyncEnabled(true);
}

void Engine::push(GameState* stan) {
	obiekty.push(stan);
	std::cout << obiekty.size() << "\n";
	
}

GameState* Engine::stos() {
		return this->obiekty.top();
}

void Engine::del() {
	delete obiekty.top();
	obiekty.pop();
	std::cout << typeid(*obiekty.top()).name() << "\n";
	std::cout << obiekty.size() << "\n";
}

void Engine::mainLoop() {
	while (okno.isOpen()) {
		//std::cout << "CZYTAM???!!\n";
		stos()->inputs();
		stos()->draw();
		okno.display();
	}
}
 
Engine::~Engine() {
	std::cout << "Zamykam ENGINE\n";
}