#include <iostream>
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(Engine* gra)
{
	gameStatePTR = gra;
	sf::Vector2u position = gameStatePTR->okno.getSize();
	//Menu background
	bkg.loadFromFile("bkg.jpg");
	float scaleX = (float)(gameStatePTR->okno.getSize().x) / (bkg.getSize().x);
	float scaleY = (float)(gameStatePTR->okno.getSize().y) / (bkg.getSize().y);
	std::cout << scaleX << scaleY;
	bkg_sprite.setTexture(bkg);
	bkg_sprite.setScale(scaleX,scaleY);
	//Menu options
	std::cout << "Tworze menu\n";
	menu = { "Nowa Gra","Opcje", "Wyjscie" };
	font.loadFromFile("retro.ttf");
	for (int x = 0; x < 3;x++) {
		text.push_back(t);
		text[x].setFont(font);
		text[x].setString(menu[x]);
		text[x].setPosition(position.x/2-text[x].getGlobalBounds().width/2, position.y/4 + x * 120);
	}
}

void MainMenu::inputs() {
		sf::Event zdarz;
		sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
			while (gameStatePTR->okno.pollEvent(zdarz)) {
				//std::cout << typeid(gameStatePTR->stos()).name() << "\n";
				if (zdarz.type == sf::Event::Closed)
					gameStatePTR->okno.close();
				else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::Q)) {
					gameStatePTR->okno.close();
				}
				else if ((text[0].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
					gameStatePTR->push(new Game(gameStatePTR));
				}
				else if ((text[2].getGlobalBounds().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
					gameStatePTR->okno.close();
			}
			for (int x = 0; x < 3; x++) {
				if (text[x].getGlobalBounds().contains(mouse))
					text[x].setFillColor(sf::Color::Red);
				else
					text[x].setFillColor(sf::Color::Blue);
			}
}

void MainMenu::draw() {
	this->gameStatePTR->okno.clear(sf::Color::Black);
	gameStatePTR->okno.draw(bkg_sprite);
	for (auto& p : text)
		this->gameStatePTR->okno.draw(p);
}

void MainMenu::update() {
	
}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
