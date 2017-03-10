#include <iostream>
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(Engine* gra)
{
	gameStatePTR = gra;
	sf::Vector2f position = static_cast<sf::Vector2f>(gameStatePTR->okno.getSize());
	//Menu background
	//bkg.loadFromFile("bkg.jpg");
	//float scaleX = (float)(gameStatePTR->okno.getSize().x) / (bkg.getSize().x);
	//float scaleY = (float)(gameStatePTR->okno.getSize().y) / (bkg.getSize().y);
	//std::cout << scaleX << scaleY;
	//bkg_sprite.setTexture(bkg);
	//bkg_sprite.setScale(scaleX,scaleY);
	//Menu options
	std::cout<<position.x;
	std::cout << "Tworze menu\n";
	mTxt = { "New game","Options", "Exit" };
	//font.loadFromFile("fonts/Game2.ttf");
	for (int x = 0; x < 3;x++) {
		mItems.push_back(std::make_unique<Text>(mTxt[x], "fonts/Game2.ttf"));
		mItems[x]->setSize(15);
		mItems[x]->setPosition(position.x / 2 - mItems[x]->GetSize().width / 2, position.y / 4 + x * 130);
	}
}

void MainMenu::inputs() {
		sf::Event zdarz;
		sf::Vector2f mouse(sf::Mouse::getPosition(gameStatePTR->okno));
			while (gameStatePTR->okno.pollEvent(zdarz)) {
				if (zdarz.type == sf::Event::Closed)
					gameStatePTR->okno.close();
				else if ((zdarz.type == sf::Event::KeyReleased) && (zdarz.key.code == sf::Keyboard::Q)) {
					gameStatePTR->okno.close();
				}
				else if ((mItems[0]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left)) {
					gameStatePTR->push(new Game(gameStatePTR));
				}
				else if ((mItems[2]->GetSize().contains(mouse)) && (zdarz.type == sf::Event::MouseButtonReleased) && (zdarz.key.code == sf::Mouse::Left))
					gameStatePTR->okno.close();
			}
			for (int x = 0; x < 3; x++) {
				if (mItems[x]->GetSize().contains(mouse))
					mItems[x]->setColor(sf::Color::Red);
				else
					mItems[x]->setColor(sf::Color::White);
			}
}

void MainMenu::draw() {
	this->gameStatePTR->okno.clear(sf::Color::Black);
	//gameStatePTR->okno.draw(bkg_sprite);
	for (auto& p : mItems)
		p->draw(gameStatePTR->okno);
}

void MainMenu::update() {
	
}

MainMenu::~MainMenu() {
	std::cout << "Zamykam MENU\n";
}
