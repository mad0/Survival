#include "Game.h"
#include <iostream>



Game::Game(Engine* gra) {
	startMsg = true;
	gameStatePTR = gra;
	p1 = Player(120);
	font.loadFromFile("fonts/FBI.ttf");
	guiStr[0] = "Ilosc zycia: ";
	guiStr[1] = "Plecak: ";
	gui[0].setString(guiStr[0]+std::to_string(p1.show_hp()));
	gui[0].setFont(font);
	gui[0].setPosition(50, 30);
	gui[0].setCharacterSize(45);

	gui[1].setString(guiStr[1] + std::to_string(p1.bagSize()));
	gui[1].setFont(font);
	gui[1].setPosition(250, 30);
	gui[1].setCharacterSize(45);
	//p1 = new Player(100, 1, 1);
	//Wsize = sf::Vector2f(gameStatePTR->okno.getSize());
	//ui = std::make_unique<GUI>("UI");
	std::cout << "Wchodze z MENU do GRY\n";
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
	while (gameStatePTR->okno.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			gameStatePTR->okno.close();
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::S) {
			//if (!quests) {
			//	quests = std::make_unique<GUI>("GUIQuests");
			//}
			//else
			//	quests = NULL;
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Space) {
			startMsg = false;
			p1.show_hp();
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
	for (auto x: gui)
		gameStatePTR->okno.draw(x);
	//if (quests)
	//	gameStatePTR->okno.draw(*quests);
}

void Game::update() {

}

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
}
