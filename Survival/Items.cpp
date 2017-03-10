#include "Items.h"
#include <iostream>

Items::Items(const std::string& name) : name(name) {
	std::cout<<"Tworze item...";
}

Items::~Items() {
	std::cout << "Niszcze item...";
}

std::string Items::getName() {
	return name;
}

//Weapons
Weapons::Weapons(const std::string& name, int Ldmg, int Hdmg) : Items(name), Ldmg(Ldmg), Hdmg(Hdmg) {
	std::cout << "Tworze bron...";
}

Weapons::~Weapons() {
	std::cout << "Tworze bron...";
}

int Weapons::getLdmg() {
	return Ldmg;
}

int Weapons::getHdmg() {
	return Hdmg;
}