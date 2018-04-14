#include "Inventory.h"

Inventory::Inventory() {
}


Inventory::~Inventory() {
}


void Inventory::addItem(Items::ItemType _itemType, int _itemID, std::string& _itemName, int _index) {
	items.push_back(Bag());
	items[_index].itemType = _itemType;
	items[_index].itemID = _itemID;
	items[_index].itemName = _itemName;
}

void Inventory::removeItem(int _bagIndex) {
}

void Inventory::showInventory() {
	std::cout << items.size()<<"\n";
	for (int x = 0; x < items.size(); x++) {
		std::cout << "Item ID: "<<items[x].itemID << "\n";
		std::cout << "Type: "<<items[x].itemType << "\n";
		std::cout << "Item name: "<<items[x].itemName << "\n";
	}
}


