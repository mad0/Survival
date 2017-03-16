#include "Character.h"
#include <iostream>
Character::Character(int hp, sf::RenderWindow& okno) :hp(hp), okno(okno) {
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	
	CharTexture.loadFromFile("gfx/player.jpg");
	Char.setTexture(CharTexture);
	Char.setPosition(50, 50);
	gra.reset(sf::FloatRect(0, 0, 1280, 720));
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

void Character::move(float x, float y) {
	Char.move(x, y);
	std::cout << "x "<<Char.getPosition().x << "\n";
	std::cout << "y"<<Char.getPosition().y << "\n";
	if (Char.getPosition().x<0)
		gra.move(50,y);
	//std::cout<<widok.getSize().x;
}

void Character::draw() {
	okno.setView(gra);

	okno.draw(Char);
}