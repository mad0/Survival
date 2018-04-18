#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

void Inventory::addWeapon(Weapons *_weapon) {
	Bag *tempBag = new Bag();
	tempBag->itemID = _weapon->getID();
	tempBag->itemName = _weapon->getName();
	bag.push_back(*tempBag);
}


void Inventory::showInventory() {
	std::cout << bag.size()<<"\n";
	for (auto& i : bag) {
		std::cout << "Item ID: "<< i.itemID << "\n";
		std::cout << "Item name: " << i.itemName << "\n";
	}
}

int Inventory::bagSize() {
	return bag.size();
}
