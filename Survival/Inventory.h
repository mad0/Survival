#pragma once
#include "Items.h"
#include <memory>

class Inventory {
private:
	struct Bag {
		Items::ItemType itemType;
		int itemID;
		std::string itemName;
	};
	std::vector<std::unique_ptr<Bag>> items;
public:
	
	void addItem(Items::ItemType _itemType, int _itemID, std::string& _itemName, int _index);
	void removeItem(int _bagIndex);
	void showInventory();
	Inventory();
	~Inventory();
};

