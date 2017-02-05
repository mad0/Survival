#include "Game.h"
#include "MainMenu.h"
#include <SFML\Graphics.hpp>


int main() {
	Game gra;
	gra.mainLoop(new MainMenu());

	return 0;
};