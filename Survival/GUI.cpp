#include "GUI.h"
#include <iostream>

//Main GUI
GUI::GUI(GUIText text, GUIShapes shape) {
	
	
}

void GUI::draw(sf::RenderWindow& okno) {
	std::cout << "dra..\n";
	//okno.draw();
};


GUI::~GUI()
{
}



//Ksztalty
GUIShapes::GUIShapes() {
	DialogBG.loadFromFile("dialog.png");
	DialogBox.setTexture(DialogBG);
	DialogBox.setScale(0.3f, 0.3f);
	DialogBox.setPosition(800, 300);
}

GUIShapes::~GUIShapes() {
	
}


//Teksty
GUIText::GUIText() {
	font.loadFromFile("retro.ttf");
	text.setFont(font);
	text.setString("Inventory...\n");
}

GUIText::~GUIText() {


}