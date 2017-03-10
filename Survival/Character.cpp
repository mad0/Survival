#include "Character.h"
#include <iostream>
Character::Character(int hp) :hp(hp) {
	//jeden = Items("lala", 1, 5);
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	weapon = std::make_unique<Weapons>("Stick", 1, 4);
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

int Character::Ldmg() {
	return weapon->getLdmg();
}

int Character::Hdmg() {
	return weapon->getHdmg();
}

std::string Character::ItemName() {
	return weapon->getName();
}