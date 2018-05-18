#include <iostream>
#include "GameState.h"
#include "Engine.h"

Engine::Engine() {
	std::cout << "Uruchamiam ENGINE...\n";
	//getState()
	window.create(sf::VideoMode(1280, 720), "Ice Syrvival - Alpha 0.0.01", sf::Style::Default);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(true);
	//speed = sf::seconds(1 / 10);
	//time = sf::Time::Zero;
}

void Engine::setState(GameState* stan) {
	stos.push(stan);
	std::cout << "Stos size: "<<stos.size() << "\n"; 
}

GameState* Engine::getState() {
	return this->stos.top();
}

void Engine::delState() {
	delete stos.top();
	stos.pop();
	std::cout <<"Ilosc obiektow na stosie, dziedziczacych po GameState "<<stos.size() << "\n";
}

void Engine::mainLoop() {
	while (window.isOpen()) {
		//time += clock.restart();
		//while (time > speed) {
		//	std::cout << time.asSeconds() << "\n";
		getState()->inputs();
		getState()->update();
		//	time -= speed;
		//}
		getState()->draw();
		window.display();
		//window.setView(window.getDefaultView());
	}
	std::cout << "Usuwam ostatni obiekt ze stosu\n";
	delState();
}
 
Engine::~Engine() {
	std::cout << "Zamykam ENGINE...\n";
}