#include "Inventory.h"

Inventory::Inventory() {
}


Inventory::~Inventory() {
}


void Inventory::addItem(Items::ItemType _itemType, int _itemID, std::string& _itemName, int _index) {
	items.push_back(std::make_unique<Bag>());
	items[_index]->itemType = _itemType;
	items[_index]->itemID = _itemID;
	items[_index]->itemName = _itemName;
}

void Inventory::removeItem(int _bagIndex) {
}

void Inventory::showInventory() {
	std::cout << items.size()<<"\n";
	for (auto& i : items) {
		std::cout << "Item ID: "<<i->itemID << "\n";
		std::cout << "Type: "<<i->itemType << "\n";
		std::cout << "Item name: "<<i->itemName << "\n";
	}
}


