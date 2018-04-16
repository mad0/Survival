#include "Inventory.h"

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

//void Inventory::addToInventory(Items::ItemType _itemType, int _itemID, std::string& _itemName, int _index) {
//	items.push_back(std::make_unique<Bag>());
//	items[_index]->itemType = _itemType;
//	items[_index]->itemID = _itemID;
//	items[_index]->itemName = _itemName;
//}

void Inventory::addToInventory(std::vector<Weapons>& _inventoryVector) {
	std::cout << "ADRES VECTORA: " << &_inventoryVector << "\n";
	bag.push_back(new Bag());
	bag[0]->itemName = _inventoryVector[0].getName();
	bag[0]->itemType = _inventoryVector[0].getItemType();
	bag[0]->itemID = _inventoryVector[0].getID();
	//std::cout << "WEAPONS INVENTORY: "<<weaponsInventory.size();
}

//template <class T>
//void Inventory::delFromInventory(int _bagIndex) {
//	std::cout << "USUWAM\n";
//	items.erase(items.begin()+_bagIndex);
//}


void Inventory::showInventory() {
	std::cout << bag.size()<<"\n";
	for (auto& i : bag) {
		std::cout << "Item ID: "<< i->itemID << "\n";
		std::cout << "Type: "<<i->itemType << "\n";
		std::cout << "Item name: "<<i->itemName << "\n";
	}
}