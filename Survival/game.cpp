#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	gameStatePTR = gra;
	//Wsize = sf::Vector2f(gameStatePTR->okno.getSize());
	//ui = std::make_unique<GUI>("UI");
	std::cout << "Wchodze z MENU do GRY\n";
	txt.emplace_back(new Text("Obudzilem sie w jakiejs ciemnej piwnicy, z przodu widze korytarz\nCo robic?", "fonts/FBI.ttf"));
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
	while (gameStatePTR->okno.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			gameStatePTR->okno.close();
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::K) {
			//if (!quests) {
			//	quests = std::make_unique<GUI>("GUIQuests");
			//}
			//else
			//	quests = NULL;
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
	txt[0]->draw(gameStatePTR->okno);
	//if (quests)
	//	gameStatePTR->okno.draw(*quests);
}

void Game::update() {

}

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
}
