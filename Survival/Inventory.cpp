#include "Inventory.h"

Inventory::Inventory(int _bagSize) {
	slotsTexture = new sf::Texture;
	slotsTexture->loadFromFile("gfx/slot.png");
	for (int x = 0; x < _bagSize; x++) {
		bagSlots.emplace_back(std::make_unique<sf::Sprite>());
		bagSlots[x]->setTexture(*slotsTexture);
		bagSlots[x]->setPosition(460+(x*64), 150);
	}
	
}

Inventory::~Inventory() {
	std::cout << "Niszcze INVENTORY...\n";
	delete slotsTexture;
	///std::cout << bagSlots.size();
	for (int x = 0; x < itemsInventory.size(); x++)
		delete itemsInventory[x];
	for (int x = 0; x < weaponsInventory.size(); x++)
		delete weaponsInventory[x];
}

void Inventory::addWeapon(Weapons *_weapon) {
	weaponsInventory.push_back(_weapon);
	bag.push_back(_weapon->getID());
	//std::cout << "WEAPONS INVENTORY: " << weaponsInventory.size() << "\n";
	//std::cout << "BAG ITEMS: " << bag.size() << "\n";
}

void Inventory::addItem(Consumable *_item) {
	itemsInventory.push_back(_item);
	std::cout << "SIZE: " << itemsInventory.size() << "\n";
	for (int x = 0; x < itemsInventory.size(); x++) {
		sf::Vector2f pos(bagSlots[x]->getPosition().x, bagSlots[x]->getPosition().y);
		std::cout << "Pozycja X: "<<bagSlots[x]->getPosition().x << "\n";
		_item->itemIcon(pos);
		bag.push_back(_item->getID());
	}
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
	for (auto& z : bagSlots) {
		_window.draw(*z);
	}
	for (auto& i : itemsInventory) {
		//i->itemIcon(sf::Vector2f(pos1));
		i->itemSetScale(0.20, 0.20);
		i->itemIconDraw(_window);
		std::cout << i << "\n";
	}
	
}
