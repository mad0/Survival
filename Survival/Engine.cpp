#include <iostream>
#include "GameState.h"
#include "Engine.h"

Engine::Engine() {
	std::cout << "Uruchamiam ENGINE...\n";
	okno.create(sf::VideoMode(1280, 720), "Ice Syrvival - Alpha 0.0.01", sf::Style::Default);
	okno.setFramerateLimit(59);
	okno.setVerticalSyncEnabled(true);
	okno.setKeyRepeatEnabled(true);
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
	std::cout <<"Ilosc obiektow na stosie, dziedziczacych po GameState "<<obiekty.size() << "\n";
}

void Engine::mainLoop() {
	while (okno.isOpen()) {
		stos()->inputs();
		stos()->update();
		stos()->draw();
		okno.display();
		okno.setView(okno.getDefaultView());
	}
	std::cout << "Usuwam ostatni obiekt ze stosu\n";
	del();
}
 
Engine::~Engine() {
	std::cout << "Zamykam ENGINE...\n";
}