#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game* gra)
{
	std::cout << "Tworze menu\n";
	//std::cout << typeid(gameStatePTR).name();
	gameStatePTR = gra;
	font.loadFromFile("retro.ttf");
	text.setFont(font);
	text.setString("Nowa Gra");
}

void MainMenu::input() {
}

void MainMenu::draw() {
	gameStatePTR->okno.clear(sf::Color::Black);
	gameStatePTR->okno.draw(text);
}

void MainMenu::update() {

}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
