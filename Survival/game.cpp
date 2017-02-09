#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	std::cout << "---------------------------\n";
	gameStatePTR = gra;
	std::cout << "Wchodze z MENU do GRY\n";
	font.loadFromFile("retro.ttf");
	text.setFont(font);
	text.setString("W GRZE\n");
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
	while (gameStatePTR->okno.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			gameStatePTR->okno.close();

		else if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Escape)) {
			gameStatePTR->del();
				
		}
		/*else if ((text[0].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
			gameStatePTR->okno.close();
		else if ((text[2].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
			gameStatePTR->okno.close();
		*/
	}
}


void Game::draw() {
	gameStatePTR->okno.clear(sf::Color::Black);
	gameStatePTR->okno.draw(text);
}

void Game::update() {

}

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
}