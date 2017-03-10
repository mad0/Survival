#include "Items.h"
#include <iostream>

Items::Items(const std::string& name, const std::string& file) : name(name), file(file) {
	std::cout<<"Tworze item...\n";
}

Items::~Items() {
	std::cout << "Niszcze item...\n";
}

std::string Items::getName() {
	return name;
}


//Weapons
Weapons::Weapons(const std::string& name, const std::string& file, int Ldmg, int Hdmg) : Items(name, file),  Ldmg(Ldmg), Hdmg(Hdmg) {
	std::cout << "Tworze bron...\n";
}

Weapons::~Weapons() {
	std::cout << "Niszcze bron...\n";
}

int Weapons::getLdmg() {
	return Ldmg;
}

int Weapons::getHdmg() {
	return Hdmg;
}

void Weapons::newWeapon() {
	Ldmg = 10;
	Hdmg = 35;
	name = "Mlot";
}