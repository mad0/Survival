#include "MainMenu.h"
#include <iostream>


MainMenu::MainMenu(Engine* gra)
{
	gameStatePTR = gra;
	sf::Vector2u position = gameStatePTR->okno.getSize();
	std::cout << "Tworze menu\n";
	menu = { "Nowa Gra","Opcje", "Wyjscie" };
	font.loadFromFile("retro.ttf");
	//std::cout << position.x;
	//std::cout << typeid(gameStatePTR).name();
	
	for (int x = 0; x < 3;x++) {
		text.push_back(t);
		text[x].setFont(font);
		text[x].setString(menu[x]);
		text[x].setPosition(position.x/2-text[x].getGlobalBounds().width/2, position.y/4 + x * 120);
	}
	std::cout << text.size();
}

void MainMenu::main() {
	while (gameStatePTR->okno.isOpen()) {
		sf::Event zdarz;
		while (gameStatePTR->okno.pollEvent(zdarz)) {
			if (zdarz.type == sf::Event::Closed)
				gameStatePTR->okno.close();
			if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Escape)) {
				break;
				gameStatePTR->okno.close();
			}

			if ((zdarz.type == sf::Event::KeyPressed) && (zdarz.key.code == sf::Keyboard::Q)) {
				//del();
				gameStatePTR->okno.close();
			}
		}
		draw();
	}
}

void MainMenu::draw() {
	this->gameStatePTR->okno.clear(sf::Color::Black);
	for (auto& p : text)
		this->gameStatePTR->okno.draw(p);
	gameStatePTR->okno.display();
}

void MainMenu::update() {
	
}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
