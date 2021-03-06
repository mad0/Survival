#include "Character.h"
#include <iostream>

Character::Character(std::string _iconFile, int _hp) :hp(_hp) {
	this->maxHp = hp;
	charTexture.loadFromFile(_iconFile);
	charSprite.setTexture(charTexture);
	//Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
	charSprite.setPosition(0,0);
//	gra.reset(sf::FloatRect(0, 0, 1280, 720));
}


Character::~Character() {
	std::cout << "Zabijam CHARACTER\n";
}

int Character::getHp() {
	if (hp >0)
		return hp;
	else 
		return hp = 0;
}

int Character::getmaxHp() {
	return maxHp;
}

bool Character::isAlive() {
	if (hp > 0)
		return true;
	else
		return false;
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

void Character::setHP(int _hp) {
		hp+= _hp;
}

void Character::setMaxHP(int _hp) {
	maxHp = maxHp - _hp;
}

Weapons * Character::getWeapon() {
	return slots.hand;

}

void Character::draw(sf::RenderWindow &_okno) {
	//_okno.setView(gra);
	_okno.draw(charSprite);
}

sf::Vector2f Character::getPosition() {
	return charSprite.getPosition();
}

void Character::setPosition(float x, float y) {
	charSprite.setPosition(x, y);
}
sf::FloatRect Character::collisionBox() {
	return charSprite.getGlobalBounds();
}