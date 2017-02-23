#include "GUI.h"
#include <iostream>
GUI::GUI() {
	font.loadFromFile("retro.ttf");
	text.setFont(font);
	text.setString("Inventory...\n");
	DialogBG.loadFromFile("dialog.png");
	DialogBox.setTexture(DialogBG);
	DialogBox.setScale(0.3f, 0.3f);
	DialogBox.setPosition(800, 300);
}


void GUI::draw(sf::RenderWindow& okno) {
	std::cout << "dra..\n";
	okno.draw(DialogBox);
};


GUI::~GUI()
{
}
