#include "Character.h"
#include <iostream>
Character::Character(int hp, sf::RenderWindow& okno) :hp(hp), okno(okno) {
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	Slots.hand = nullptr;
	CharIdle.loadFromFile("gfx/char/icons/x32.png");
	Char.setTexture(CharIdle);
	//Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
	Char.setPosition(0,0);
	gra.reset(sf::FloatRect(0, 0, 1280, 720));
	//Char.setOrigin(32, 32);
	//Char.setScale(0.7, 0.7);
}	

Character::~Character() {
}

int Character::show_hp() {
	return hp;
}

int Character::bagSize() {
	return 200;
}

void Character::move(short x, short y) {
	Char.move(x, y);
}

void Character::anim(int x, int y) {
	if (x==-32)
		Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
	if (x == 32)
		Char.setTextureRect(sf::IntRect(0, 0, 32, 32));
	if (y == -32)
		Char.setTextureRect(sf::IntRect(96, 0, 32, 32));
	if (y == 32)
		Char.setTextureRect(sf::IntRect(64, 0, 32, 32));
}

void Character::setWeapon(Weapons * _weapon) {
	Slots.hand = _weapon;
}

Weapons * Character::getWeapon() {
	return Slots.hand;
}

void Character::draw() {
	okno.setView(gra);
	okno.draw(Char);
}

sf::Vector2f Character::getPosition() {
	return Char.getPosition();
}

void Character::setPosition(float x, float y) {
	Char.setPosition(x, y);
};