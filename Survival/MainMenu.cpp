#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(Game* gra)
{
	game = gra;
	std::cout << "MAINMENU\n";
	font.loadFromFile("font.ttf");
	text.setFont(font);
	text.setString("lalala");
}

void MainMenu::input() {
}

void MainMenu::draw() {
	std::cout << "dupa";
	game->okno.draw(text);
}

void MainMenu::update() {


}
