#pragma once
#include "Items.h"
#include <memory>

class Inventory {
private:
	struct Bag {
		Items::ItemType itemType;
		int itemID;
		std::string itemName;
		~Bag() {
			std::cout << "USUWAM ITEM\n";
		};
	};
	std::vector<Bag*> bag;
	//std::vector<std::unique_ptr<Weapons>> weaponsInventory;
	//std::vector<std::unique_ptr<Consumable>> consumableInventory;

public:
	//void addToInventory(Items::ItemType _itemType, int _itemID, std::string& _itemName, int _index);

	void addToInventory(std::vector<Weapons>& _inventoryVector);

	//void delFromInventory(int _bagIndex);
	//template <class T>
	void showInventory();
	Inventory();
	~Inventory();
};
