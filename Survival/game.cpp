#include <iostream>
#include "GameState.h"
#include "Game.h"
#include "MainMenu.h"

Game::Game() {
	okno.create(sf::VideoMode(1440, 800), "Syrvival - Alpha");
}

void Game::mainLoop() {
	while (okno.isOpen()) {
		sf::Event zdarz;
		while (okno.pollEvent(zdarz)) {
			if (zdarz.type == sf::Event::Closed)
				okno.close();
			if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Escape))
				okno.close();
			if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::D)) {
				del();
				okno.close();
			}	
		}
		if (!obiekty.empty())
			top()->draw();
		okno.display();
	}
}

void Game::push(GameState* stan) {
	obiekty.push(stan);
}

GameState* Game::top() {
		return obiekty.top();
}

void Game::del() {
	//std::cout << typeid(obiekty.top()).name();
	delete obiekty.top();
	obiekty.pop();
}

Game::~Game() {
	std::cout << "Zamykam GRE\n";
}