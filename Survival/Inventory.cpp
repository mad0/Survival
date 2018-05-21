#include "Inventory.h"

Inventory::Inventory(int _bagSize) {
	std::cout << "Tworze inventory...\n";
	//TEMPORARY ITEMS DB 
	itemsDB.emplace(std::pair<int, Items*>(1, new Potions(Items::POTION, "gfx/potion.png", "Simple potion", 5, 11)));
	itemsDB.emplace(std::pair<int, Items*>(2, new Food(Items::FOOD, "gfx/banana.png", "Banana", 12)));
	itemsDB.emplace(std::pair<int, Items*>(3, new Weapons(Items::WEAPON, "gfx/dagger.png", "Simple Dagger", 6, 12)));

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
	if (itemsDB.size() > 0) {
		for (auto& e : itemsDB) {
			delete e.second;
		}
		itemsDB.clear();
	}
}

void Inventory::addToBag(int _itemID, int _stackSize) {
	//if (std::find(bag.begin(), bag.end(), _itemID == bag.end()))
	std::cout << "tuuuuuuuuuuu";
	if (bag.size() == 0) {
		bag.emplace_back(std::make_pair(_itemID, _stackSize));
	}
	else {
		for (auto& i : bag) {
			if (i.first == _itemID)
				i.second += _stackSize;
			else 
				bag.emplace_back(std::make_pair(_itemID, _stackSize));
		}
	}
	std::cout << "Show number tems in bag: " << bag.size() << "\n";
	//bag.push_back(std::make_pair(_itemID, _stackSize));
	//std::cout << bag.at(1).first << ":" << bag.at(1).first << "\n";
	//std::cout << bagSlots.size();
	std::cout << bag.size();
	//sf::Vector2f pos(bagSlots[bag.size()-1]->getPosition().x+5, bagSlots[bag.size()-1]->getPosition().y+5);
	//getItem<Items>(_itemID)->itemIcon(pos);


	//if (std::find(bag.begin(), bag.end(), _item->getID()) == bag.end()) {
	//	bag.push_back(_item);
} 


void Inventory::delItem() {
}

void Inventory::showInventory() {
	for (auto& item : bag) {
			std::cout << "Item ID: " << item.first <<"\tItem name: " << getItem<Items>(item.first)->getName() << " = "<< item.second<<"\n";
	}
	std::cout << "Show number tems in bag: " << bag.size() << "\n";
	//std::cout << "ID's items in bag: ";
	//for (auto&c : bag)
	//	std::cout << c << "\n";
}

//int Inventory::bagSize() {
//	return bag.size();
//}

void Inventory::drawInventory(sf::RenderWindow & _window) {
	//BAG SLOTS BACKGROUND
	for (auto& z : bagSlots) {
		_window.draw(*z);
	}

	//ITEMS IN SLOTS
	for (auto& i : bag) {
		getItem<Items>(i.first)->itemSetScale(1, 1);
		getItem<Items>(i.first)->itemIconDraw(_window);
	}		
}
