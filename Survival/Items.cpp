#include "Items.h"
#include <iostream>

Items::Items(const std::string& name, const std::string& file) : name(name), file(file) {
	std::cout<<"Tworze item...\n";
}

Items::~Items() {
	std::cout << "Niszcze item...\n";
}

std::string Items::getName() {
	return name;
}


//Weapons
Weapons::Weapons(const std::string& name, const std::string& file, int Ldmg, int Hdmg) : Items(name, file),  Ldmg(Ldmg), Hdmg(Hdmg) {
	std::cout << "Tworze bron...\n";
}

Weapons::~Weapons() {
	std::cout << "Niszcze bron...\n";
}

int Weapons::getLdmg() {
	return Ldmg;
}

int Weapons::getHdmg() {
	return Hdmg;
}

void Weapons::newWeapon() {
	Ldmg = 10;
	Hdmg = 35;
	name = "Mlot";
	file = "gfx/hala.png";
	texture.loadFromFile(file);
	icon.setTexture(texture);
}

void Weapons::Icon(sf::Vector2f wsize) {
	texture.loadFromFile(file);
	icon.setTexture(texture);
	//icon.setScale(0.7,0.7);
	icon.setPosition(sf::Vector2f(wsize.x/2-icon.getGlobalBounds().width/2, wsize.y - 150));
}

void Weapons::IconDraw(sf::RenderWindow & okno)
{
	okno.draw(icon);
}