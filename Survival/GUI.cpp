#include <iostream>
#include "GUI.h"
#include "Character.h"

GUI::GUI(Character *_p1)  {
	p1 = _p1;
	bgTexture.loadFromFile("gfx/hpBG.png");
	hpBG.setTexture(&bgTexture);
	hpBG.setSize(sf::Vector2f(210, 20));
	hpBG.setPosition(sf::Vector2f(20, 600));
	barTexture.loadFromFile("gfx/hpBAR.png");
	hpBar.setTexture(&barTexture);
	hpBar.setPosition(sf::Vector2f(20, 600));
	hpBar.setSize(sf::Vector2f(210, 20));
	std::cout << "TWORZE GUI....\n";
	panels.emplace_back(std::make_unique<GUIPanel>(1, sf::Vector2f(0, 0), sf::Vector2f(300, 200), true));
	panels.emplace_back(std::make_unique<GUIPanel>(2, sf::Vector2f(980, 0), sf::Vector2f(300, 200), true));
	panels.emplace_back(std::make_unique<GUIPanel>(3, sf::Vector2f(0, 528), sf::Vector2f(1280, 192), true));
	for (auto& p : panels)
		p->setColor(sf::Color(48, 34, 6, 255));
}

GUI::~GUI() {
}

void GUI::draw(sf::RenderWindow &_window) {
	for (auto& p : panels) {
		if (p->getVisible())
			p->draw(_window);
	}
	_window.draw(hpBG);
	if (p1->isAlive()) {
		_window.draw(hpBar);
	}
		
}

void GUI::drawHP() {
	float bar = (250*(static_cast<float>(p1->getHp()) / static_cast<float>(p1->getmaxHp())));
	std::cout << "BARD: " << bar << "\n";
	//hpBar.setScale(bar, 1);
	hpBar.setTextureRect(sf::IntRect(0.0,0.0,bar,25.0));
}

void GUI::update(){
		drawHP();
}


