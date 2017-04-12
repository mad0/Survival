#include "Character.h"
#include <iostream>
Character::Character(int hp, sf::RenderWindow& okno) :hp(hp), okno(okno) {
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	
	CharIdle.loadFromFile("gfx/char/char.png");
	Char.setTexture(CharIdle);
	Char.setTextureRect(sf::IntRect(32, 0, 32, 32));
	Char.setPosition(32,32);
	gra.reset(sf::FloatRect(0, 0, 1280, 720));
	Char.setOrigin(0, 0);
	//Char.setScale(0.5, 0.5);
}	

Character::~Character()
{
}

int Character::show_hp() {
	return hp;
}

int Character::bagSize() {
	return 200;
}

void Character::move(short x, short y) {
	anim(x, y);
	Char.move(x, y);
	
	//sf::Vector2f cur = Char.getPosition();
	//std::cout << "--------------CURR  X=" << cur.x << "CURR  Y=" << cur.y << "\n";
	//std::cout << "--------------NEXT  X=" << cur.x + move.x << "NEXT  Y=" << cur.y + move.y << "\n";
	/*Char.setPosition(Char.getPosition() + move);
	if (Char.getPosition().y + move.y < 0)
		Char.setPosition(Char.getPosition().x, 0);
	if (Char.getPosition().y + move.y >288)
		Char.setPosition(Char.getPosition().x, 288);
	if (Char.getPosition().x+move.x<0)
		Char.setPosition(0, Char.getPosition().y);
	if (Char.getPosition().x+move.x>288)
		Char.setPosition(288, Char.getPosition().y);
	*/
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