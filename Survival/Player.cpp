#include "Player.h"
#include <iostream>
Player::Player(int hp) :hp(hp) {
	//jeden = Items("lala", 1, 5);
	//bag.push_back(std::make_unique<Items>("Mlotek", 1,3));
}

Player::~Player()
{
}

int Player::show_hp() {
	return hp;
}

int Player::bagSize() {
	return 1;
}
