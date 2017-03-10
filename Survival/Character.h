#pragma once
#include <string>

class Character {
private:
	int hp;
	std::string Iname;
	//std::vector <std::unique_ptr<Items>> bag;
	//Items jeden;
public:
	Character(int);
	~Character();
	int show_hp();
	int bagSize();
};

