#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	map = std::make_unique<Map>("gfx/tile.png");
	map->LoadTile();
	p1 = std::make_unique<Character>(128);
	gameStatePTR = gra;
	Wsize = sf::Vector2f(gameStatePTR->okno.getSize());
	weapon = std::make_unique<Weapons>("Sword", "gfx/sword1.png", 1, 4);
	weapon->Icon(Wsize);
	font.loadFromFile("fonts/Vecna.otf");
	guiStr[0] = "Health points ";
	guiStr[1] = "Weapon: ";
	guiStr[2] = "Damage: ";
	for (int x=0;x<3;x++) {
		gui[x].setFont(font);
		gui[x].setCharacterSize(25);
	}
	//HP
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->show_hp()));
	gui[0].setPosition(50, Wsize.y-100);
	//Nazwa broni
	gui[1].setString(guiStr[1] + weapon->getName());
	gui[1].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 100);
	//Obrazenia
	gui[2].setString(guiStr[2] + std::to_string(weapon->getLdmg()) + "-" + std::to_string(weapon->getHdmg()));
	gui[2].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 75);
	

	std::cout << "Wchodze z MENU do GRY\n";
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
	while (gameStatePTR->okno.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			gameStatePTR->okno.close();
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::S) {

		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Space) {
			weapon->newWeapon();
		}

	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		gameStatePTR->del();
}


void Game::draw() {
	gameStatePTR->okno.clear();
	for (auto x: gui)
		gameStatePTR->okno.draw(x);
	weapon->IconDraw(gameStatePTR->okno);
	map->draw(gameStatePTR->okno);
}

void Game::update() {
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->show_hp()));
	gui[1].setString(guiStr[1] + weapon->getName());
	gui[2].setString(guiStr[2] + std::to_string(weapon->getLdmg()) + "-" + std::to_string(weapon->getHdmg()));
}

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
}
