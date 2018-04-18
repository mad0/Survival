#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
	std::cout << "Niszcze INVENTORY...\n";
}

void Inventory::addWeapon(Weapons *_weapon) {
	weaponsInventory.push_back(_weapon);
	bag.push_back(_weapon->getID());
	std::cout << "WEAPONS INVENTORY: " << weaponsInventory.size() << "\n";
	std::cout << "BAG ITEMS: " << bag.size() << "\n";
}

void Inventory::addItem(Consumable *_item) {
	itemsInventory.push_back(_item);
	bag.push_back(_item->getID());
	std::cout << "ITEMS INVENTORY: " << itemsInventory.size();
}

void Inventory::delItem() {
}

void Inventory::showInventory() {
	for (auto& i : bag) {
		std::cout << "ITEM ID's:" << i << "\n";
		for (auto& weap : weaponsInventory) {
			if (weap->getID() == i)
				std::cout << weap->getName() << "\n";
		}
		for (auto& consum : itemsInventory) {
			if (consum->getID() == i)
				std::cout << consum->getName() << "\n";
		}
	}
}

int Inventory::bagSize() {
	return bag.size();
}
