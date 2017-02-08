#include "Game.h"
#include <SFML\Graphics.hpp>
#include "MainMenu.h"
#include <iostream>

int main() {
	{
		Game gra;
		gra.push(new MainMenu(&gra));
		gra.mainLoop();
		std::cout << "koniec\n";
	}
	return 0;
};