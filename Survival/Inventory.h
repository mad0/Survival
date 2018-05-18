#pragma once
#include <memory>
#include "Items.h"

class Inventory {
private:
	std::vector<std::unique_ptr<sf::Sprite>> bagSlots;
	sf::Texture *slotsTexture;
	int inventorySize;
	std::vector<Items*> bag;
	std::vector<Weapons*> weaponsInventory;
	std::vector<Items*> consumInventory;
	bool isVisible = false;
public:
	void addWeapon(Weapons *_weapon);
	void addItem(Items *_item);
	void createItem(Items *_item);
	//void delWeapon();
	void delItem();
	void showInventory();
	int bagSize();
	int itemB();
	void drawInventory(sf::RenderWindow& _window);
	Inventory(int _bagSize);
	~Inventory();
};
