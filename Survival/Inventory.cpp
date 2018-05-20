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
	for (int x = 0; x < consumInventory.size(); x++)
		delete consumInventory[x];
	for (int x = 0; x < weaponsInventory.size(); x++)
		delete weaponsInventory[x];
}

void Inventory::addWeapon(Weapons *_weapon) {
	weaponsInventory.push_back(_weapon);
	//bag.push_back(_weapon->getID());
	
}

void Inventory::addItem(Items *_item) {
	consumInventory.push_back(_item);
	
	for (int x = 0; x < consumInventory.size(); x++) {
		sf::Vector2f pos(bagSlots[x]->getPosition().x, bagSlots[x]->getPosition().y+5);
		_item->itemIcon(pos);
	}
}
void Inventory::createItem(Items *_item) {
	//if (std::find(bag.begin(), bag.end(), _item->getID()) == bag.end()) {
	//	bag.push_back(_item);
	//} 
}


void Inventory::delItem() {
}

void Inventory::showInventory() {
	for (auto& weap : weaponsInventory) {
		std::cout << "Item ID: " << weap->getID() << "\tItem name: " << weap->getName() << "\n";
	}
	for (auto& consum : consumInventory) {
		int id = consum->getID();
			std::cout << "Item ID: " << id << "\tItem name: " << consum->getName() << "\n";
	}
	std::cout << "Show number intems in bag: " << bag.size() << "\n";
	std::cout << "ID's items in bag: ";
	for (auto&c : bag)
		std::cout << c << "\n";
}

int Inventory::bagSize() {
	return consumInventory.size() + weaponsInventory.size();
}

void Inventory::drawInventory(sf::RenderWindow & _window) {
	//BAG SLOTS BACKGROUND
	for (auto& z : bagSlots) {
		_window.draw(*z);
	}

	//ITEMS IN SLOTS
	//for (auto& i : bag) {
	//	for (auto&x : consumInventory) {
	//		if (x->getID() == i) {
	////			x->itemSetScale(1, 1);
	//			x->itemIconDraw(_window);
	//		}
	//	}
		
	//}
			
}
