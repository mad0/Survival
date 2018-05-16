#pragma once
#include <memory>
#include "Items.h"

class Inventory {
private:
	std::vector<std::unique_ptr<sf::Sprite>> bagSlots;
	sf::Texture *slotsTexture;
	int inventorySize;
	std::vector<int> bag;
	std::vector<Weapons*> weaponsInventory;
	std::vector<Consumable*> consumInventory;
	bool isVisible = false;
public:
	void addWeapon(Weapons *_weapon);
	void addItem(Consumable *_item);
	//void delWeapon();
	void delItem();
	void showInventory();
	int bagSize();
	void drawInventory(sf::RenderWindow& _window);
	Inventory(int _bagSize);
	~Inventory();
};
