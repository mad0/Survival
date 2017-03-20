#include "Character.h"
#include <iostream>
Character::Character(int hp, sf::RenderWindow& okno) :hp(hp), okno(okno) {
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	
	CharTexture.loadFromFile("gfx/player.jpg");
	Char.setTexture(CharTexture);
	Char.setPosition(256,32);
	gra.reset(sf::FloatRect(0, 0, 1280, 720));
	Char.setOrigin(0, 0);
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

void Character::move(bool coll, sf::Vector2f move) {
	sf::Vector2f cur = Char.getPosition();
	std::cout << "--------------CURR  X=" << cur.x << "CURR  Y=" << cur.y << "\n";
	std::cout << "--------------NEXT  X=" << cur.x + move.x << "NEXT  Y=" << cur.y + move.y << "\n";
	Char.setPosition(Char.getPosition() + move);
	if (cur.y + move.y < 0)
		Char.setPosition(cur.x, 0);
	if (cur.y + move.y >288)
		Char.setPosition(cur.x, 288);
	if (cur.x+move.x<0)
		Char.setPosition(0, cur.y);
	if (cur.x+move.x>288)
		Char.setPosition(288, cur.y);
}


void Character::draw() {
	okno.setView(gra);
	okno.draw(Char);
}

sf::FloatRect Character::getBounds() {
	return Char.getGlobalBounds();
}

sf::Vector2f Character::getPosition() {
	return Char.getPosition();
}

void Character::setPosition(float x, float y) {
	Char.setPosition(x, y);
};