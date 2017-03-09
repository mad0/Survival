#pragma once
#include "Items.h"
#include <vector>
#include <memory>

class Player {
private:
	int hp;
	std::vector <std::unique_ptr<Items>> bag;
	//Items jeden;
public:
	Player(int hp=0);
	~Player();
	int show_hp();
	int bagSize();
};

