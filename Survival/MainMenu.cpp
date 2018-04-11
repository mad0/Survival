#include <iostream>
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(Engine* _menu) {
	engine = _menu;
	sf::Vector2f position = static_cast<sf::Vector2f>(engine->window.getSize());
	//Menu options
	std::cout<<position.x;
	std::cout << "Tworze menu\n";
	mTxt = { "New game","Options", "Exit" };
	for (int x = 0; x < 3;x++) {
		mItems.push_back(std::make_unique<Text>(mTxt[x], "fonts/Game2.ttf"));
		mItems[x]->setSize(15);
		mItems[x]->setPosition(position.x / 2 - mItems[x]->GetSize().width / 2, position.y / 4 + x * 130);
	}
}

void MainMenu::inputs() {
		sf::Event zdarz;
		sf::Vector2f mouse(sf::Mouse::getPosition(engine->window));
			while (engine->window.pollEvent(zdarz)) {
				if (zdarz.type == sf::Event::Closed)
					engine->window.close();
				else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::Q)) {
					engine->window.close();
				}
				else if ((mItems[0]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
					engine->setState(new Game(engine));
				}
				else if ((mItems[2]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
					engine->window.close();
			}
			for (int x = 0; x < 3; x++) {
				if (mItems[x]->GetSize().contains(mouse))
					mItems[x]->setColor(sf::Color::Red);
				else
					mItems[x]->setColor(sf::Color::White);
			}
}

void MainMenu::draw() {
	engine->window.clear(sf::Color::Black);
	for (auto& p : mItems)
		p->draw(engine->window);
}

void MainMenu::update() {

}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
