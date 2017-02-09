#include "Engine.h"
#include <SFML\Graphics.hpp>
#include "MainMenu.h"
#include <iostream>

int main() {
	{
		Engine gra;
		gra.push(new MainMenu(&gra));
		gra.mainLoop();
	}
	return 0;
};