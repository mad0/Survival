#pragma once
#include "Items.h"
#include <memory>

class Inventory {
private:
	std::vector<std::unique_ptr<Weapons>> weaponInvent;
	std::vector<std::unique_ptr<Consumable>> consumableInvent;
public:
	void addItem(const Items* _item);
	void removeItem(int _bagIndex);
	void showItems();
	Inventory();
	~Inventory();
};

