#include "Inventory.h"

Inventory::Inventory(int _bagSize) {
	this->bagTexture.loadFromFile("gfx/Inventory.png");
	this->bagSprite.setTexture(bagTexture);
	this->bagSprite.setPosition(460, 150);
}

Inventory::~Inventory() {
	std::cout << "Niszcze INVENTORY...\n";
}

void Inventory::addWeapon(Weapons *_weapon) {
	weaponsInventory.push_back(_weapon);
	bag.push_back(_weapon->getID());
	std::cout << "WEAPONS INVENTORY: " << weaponsInventory.size() << "\n";
	std::cout << "BAG ITEMS: " << bag.size() << "\n";
}

void Inventory::addItem(Consumable *_item) {
	int s = itemsInventory.size();
	sf::Vector2f pos1(465+(s*64), 155+(s*64));
	_item->itemIcon(pos1);
	itemsInventory.push_back(_item);
	bag.push_back(_item->getID());
	std::cout << "ITEMS INVENTORY: " << itemsInventory.size();
}

void Inventory::delItem() {
}

void Inventory::showInventory() {
	for (auto& i : bag) {
		std::cout << "ITEM ID's:" << i << "\n";
		for (auto& weap : weaponsInventory) {
			if (weap->getID() == i)
				std::cout << weap->getName() << "\n";
		}
		for (auto& consum : itemsInventory) {
			if (consum->getID() == i)
				std::cout << consum->getName() << "\n";
		}
	}
}

int Inventory::bagSize() {
	return itemsInventory.size() + weaponsInventory.size();
}

void Inventory::drawInventory(sf::RenderWindow & _window) {
	_window.draw(bagSprite);
	for (auto& i : itemsInventory) {
		//i->itemIcon(sf::Vector2f(pos1));
		i->itemSetScale(0.20, 0.20);
		i->itemIconDraw(_window);
		std::cout << i << "\n";
	}
	
}
