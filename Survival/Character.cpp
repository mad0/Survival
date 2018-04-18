#include "Character.h"
#include <iostream>

Character::Character(sf::RenderWindow& _okno, int _hp) :okno(_okno), hp(_hp) {
	this->maxHp = hp;
	charTexture.loadFromFile("gfx/char/icons/x32.png");
	charSprite.setTexture(charTexture);
	//Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
	charSprite.setPosition(0,0);
	gra.reset(sf::FloatRect(0, 0, 1280, 720));
	//Char.setOrigin(32, 32);
	//Char.setScale(0.7, 0.7);
}	

Character::~Character() {
}

int Character::getHp() {
	return hp;
}

int Character::getmaxHp() {
	return maxHp;
}

void Character::move(short x, short y) {
	charSprite.move(x, y);
}

//void Character::anim(int x, int y) {
//	if (x==-32)
////		Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
//	if (x == 32)
///		Char.setTextureRect(sf::IntRect(0, 0, 32, 32));
//	if (y == -32)
///	if (y == 32)
//		Char.setTextureRect(sf::IntRect(64, 0, 32, 32));
//}

void Character::equipWeapon(Weapons * _weapon) {
	slots.hand = _weapon;
}

Weapons * Character::getWeapon() {
	return slots.hand;
}

void Character::draw() {
	okno.setView(gra);
	okno.draw(charSprite);
}

sf::Vector2f Character::getPosition() {
	return charSprite.getPosition();
}

void Character::setPosition(float x, float y) {
	charSprite.setPosition(x, y);
};