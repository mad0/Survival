#include "Engine.h"
#include "MainMenu.h"
#include <iostream>

int main() {
	Engine gra;
	gra.setState(new MainMenu(&gra));
	gra.mainLoop();
return 0;
};