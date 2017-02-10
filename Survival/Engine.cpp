#include <iostream>
#include "GameState.h"
#include "Engine.h"

Engine::Engine() {
	okno.create(sf::VideoMode(1440,800), "Syrvival - Alpha", sf::Style::Fullscreen);
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
	std::cout << obiekty.size() << "\n";
}

void Engine::mainLoop() {
	while (okno.isOpen()) {
		stos()->inputs();
		stos()->draw();
		okno.display();
	}
	std::cout << "Usuwam ostatni obiekt ze stosu\n";
	del();
}
 
Engine::~Engine() {
	std::cout << "Zamykam ENGINE\n";
}