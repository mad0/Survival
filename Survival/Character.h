#pragma once
#include "Items.h"
#include <vector>
#include <memory>

class Character {
private:
	int hp;
	std::string Iname;
	//std::vector <std::unique_ptr<Items>> bag;
	//Items jeden;
	std::unique_ptr<Weapons> weapon;
public:
	Character(int);
	~Character();
	std::string ItemName();
	int show_hp();
	int bagSize();
	int Ldmg();
	int Hdmg();
};

