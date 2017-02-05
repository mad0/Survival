#include "Game.h"
#include "GameState.h"

Game::Game() {
	okno.create(sf::VideoMode(1440,800),"Syrvival - Alpha");
}

void Game::mainLoop(GameState* state) {
	while (okno.isOpen()) {
		okno.clear(sf::Color::Black);
		state->draw();
		okno.display();

	};

}


Game::~Game() {


}