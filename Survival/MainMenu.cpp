#include "MainMenu.h"

MainMenu::MainMenu(Game* gra) {
	f_menu.loadFromFile("font.ttf");
	t_menu.setFont(f_menu);
	t_menu.setString("Nowa gra");
}

MainMenu::~MainMenu() {


}

void MainMenu::inputs() {


}

void MainMenu::update() {

}

void MainMenu::draw() {
	gra->okno.draw(t_menu);
}