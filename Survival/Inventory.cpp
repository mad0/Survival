#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

void Inventory::addToInventory(int _itemId, const std::string& _itemName) {
	int bagSize = bag.size();
	bag.push_back(new Bag());
	bag[bagSize]->itemID = _itemId;
	bag[bagSize]->itemName = _itemName;
	//std::cout << "WEAPONS INVENTORY: "<<weaponsInventory.size();
}

void Inventory::showInventory() {
	std::cout << bag.size()<<"\n";
	for (auto& i : bag) {
		std::cout << "Item ID: "<< i->itemID << "\n";
		std::cout << "Item name: "<<i->itemName << "\n";
	}
}

int Inventory::bagSize() {
	return bag.size();
}
