#include "Game.h"
#include <iostream>
#include "GameState.h"

Game::Game() {
	okno.create(sf::VideoMode(1440, 800), "Syrvival - Alpha");
}



void Game::run() {
	std::cout << typeid(pop()).name();
	while (okno.isOpen()) {
		okno.clear(sf::Color::Blue);
		pop()->draw();
		okno.display();
	}
	
}

void Game::push(GameState* stan) {
	obiekty.push(stan);
	std::cout << obiekty.size();
}


GameState* Game::pop() {
	return this->obiekty.top();
}

Game::~Game() {

}