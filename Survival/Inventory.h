#pragma once
#include <memory>
#include "Items.h"

class Inventory {
private:
	std::map<int, Items*> itemsDB;
	std::vector<std::unique_ptr<sf::Sprite>> bagSlots;
	sf::Texture *slotsTexture;
	int bagSize;
	std::vector<std::pair<int, int>> bag;
	bool isVisible = false;
	
public:
	void addToBag(int _itemID, int _stackSize);
	template <typename T>
	T* getItem(int _itemID);
	//void delWeapon();
	void delItem();
	void showInventory();
	//int bagSize();
	void drawInventory(sf::RenderWindow& _window);
	Inventory(int _bagSize);
	~Inventory();
};

template<typename T>
inline T * Inventory::getItem(int _itemID) {
	return static_cast<T*>(itemsDB.at(_itemID));
}
