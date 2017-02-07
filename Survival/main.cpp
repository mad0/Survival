#include "Game.h"
#include <SFML\Graphics.hpp>
#include "MainMenu.h"


int main() {
	Game gra;
	gra.push(new MainMenu(&gra));
	gra.run();
	
	return 0;
};