#pragma once
#include <memory>
#include "Items.h"

class Inventory {
private:
	std::vector<int> bag;
	std::vector<Weapons*> weaponsInventory;
	std::vector<Consumable*> itemsInventory;
public:
	void addWeapon(Weapons *_weapon);
	void addItem(Consumable *_item);
	//void delWeapon();
	void delItem();
	void showInventory();
	int bagSize();
	Inventory();
	~Inventory();
};
