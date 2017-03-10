#include "Character.h"
#include <iostream>
Character::Character(int hp) :hp(hp) {
	//bag.push_back(std::make_unique<Weapons>("Mlotek", 1,3));
	//
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
