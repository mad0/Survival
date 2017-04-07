#include <iostream>
#include "GameState.h"
#include "Engine.h"

Engine::Engine() {
	std::cout << "Uruchamiam ENGINE...\n";
	okno.create(sf::VideoMode(1280, 720), "Ice Syrvival - Alpha 0.0.01", sf::Style::Default);
	okno.setFramerateLimit(60);
	okno.setVerticalSyncEnabled(true);
	okno.setKeyRepeatEnabled(false);
	//speed = sf::seconds(1 / 10);
	//time = sf::Time::Zero;
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
		//time += clock.restart();
		//while (time > speed) {
		//	std::cout << time.asSeconds() << "\n";
			stos()->inputs();
			stos()->update();
		//	time -= speed;
		//}
		stos()->draw();
		okno.display();
		//okno.setView(okno.getDefaultView());
	}
	std::cout << "Usuwam ostatni obiekt ze stosu\n";
	del();
}
 
Engine::~Engine() {
	std::cout << "Zamykam ENGINE...\n";
}