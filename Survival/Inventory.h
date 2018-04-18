#pragma once
#include "Items.h"
#include <memory>

class Inventory {
private:
	struct Bag {
		//Items::ItemType itemType;
		int itemID;
		std::string itemName;
		~Bag() {
			std::cout << "USUWAM ITEM\n";
		};
	};
	std::vector<Bag> bag;
public:
	void addWeapon(Weapons *_weapon);
	//void delFromInventory(int _bagIndex);
	void showInventory();
	int bagSize();
	Inventory();
	~Inventory();
};
