#include "Game.h"
#include <iostream>

int Game::num = 0;

Game::Game(Engine* gra) {
	num++;
	std::cout << "Stworzono "<<num<< "obiektow GRY\n";
	gameStatePTR = gra;
	std::cout << "Wchodze z MENU do GRY\n";
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
	while (gameStatePTR->okno.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			gameStatePTR->okno.close();
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::I) {
			if (!inv)
				inv = true;
			else
				inv = false;
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::L) {
			
		}

		/*else if ((text[0].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
			gameStatePTR->okno.close();
		else if ((text[2].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
			gameStatePTR->okno.close();
		*/
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		gameStatePTR->del();
}


void Game::draw() {
	gameStatePTR->okno.clear(sf::Color::Black);
	//if (inv)
	//	gui.gameStatePTR->okno);
	gameStatePTR->okno.draw(gui);
}

void Game::update() {

}

Game::~Game() {
	num--;
	std::cout << "Wychodze z GRY do MENU\n";
}