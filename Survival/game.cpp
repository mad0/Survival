#include "Game.h"
#include <iostream>



Game::Game(Engine* gra) {
	p1 = std::make_unique<Character>(128);
	startMsg = true;
	gameStatePTR = gra;
	Wsize = sf::Vector2f(gameStatePTR->okno.getSize());
	font.loadFromFile("fonts/Vecna.otf");
	guiStr[0] = "Health points ";
	guiStr[1] = "Weapon: ";
	guiStr[2] = "Damage: ";
	//HP
	gui[0].setString(guiStr[0]+"\n      "+std::to_string(p1->show_hp()));
	gui[0].setFont(font);
	gui[0].setPosition(50, Wsize.y-100);
	gui[0].setCharacterSize(25);
	//Plecak
	//Nazwa broni
	gui[1].setString(guiStr[1] + p1->ItemName());
	gui[1].setFont(font);
	gui[1].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 100);
	gui[1].setCharacterSize(25);
	//Obrazenia
	gui[2].setString(guiStr[2] + std::to_string(p1->Ldmg())+"-"+ std::to_string(p1->Hdmg()));
	gui[2].setFont(font);
	gui[2].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 75);
	gui[2].setCharacterSize(25);
	

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
			//p1.show_hp();
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
