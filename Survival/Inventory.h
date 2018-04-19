#pragma once
#include <memory>
#include "Items.h"

class Inventory {
private:
	sf::Sprite bagSprite;
	sf::Texture bagTexture;
	std::vector<int> bag;
	std::vector<Weapons*> weaponsInventory;
	std::vector<Consumable*> itemsInventory;
	bool isVisible = false;
public:
	void addWeapon(Weapons *_weapon);
	void addItem(Consumable *_item);
	//void delWeapon();
	void delItem();
	void showInventory();
	int bagSize();
	void drawInventory(sf::RenderWindow& _window);
	Inventory();
	~Inventory();
};
