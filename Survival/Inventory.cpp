#include "Inventory.h"

Inventory::Inventory(int _bagSize) {
	std::cout << "Tworze inventory...\n";
	//TEMPORARY ITEMS DB 
	itemsDB.emplace(std::pair<int, Items*>(1, new Potions(Items::POTION, "gfx/potion.png", "Simple potion", 5, 11)));
	itemsDB.emplace(std::pair<int, Items*>(2, new Food(Items::FOOD, "gfx/banana.png", "Banana", 12)));
	itemsDB.emplace(std::pair<int, Items*>(3, new Weapons(Items::WEAPON, "gfx/dagger.png", "Simple Dagger", 6, 12)));
	font.loadFromFile("fonts/Vecna.otf");
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
	bool found = false;
	for (auto& it : bag) {
		if (it.first == _itemID) {
			found = true;
			it.second += _stackSize; }
	}
	if (!found) {
		bag.emplace_back(std::make_pair(_itemID, _stackSize));
		sf::Vector2f pos(bagSlots[bag.size() - 1]->getPosition().x + 5, bagSlots[bag.size() - 1]->getPosition().y + 5);
		getItem<Items>(_itemID)->itemIcon(pos);
		sf::Text txt;
		txt.setPosition(pos.x+4, pos.y);
		txt.setFillColor(sf::Color::Black);
		txt.setFont(font);
		txt.setCharacterSize(16);
		itemsStack.emplace_back(std::make_unique<sf::Text>(txt));
	}
} 

void Inventory::delItem(int _itemID) {
	for (int x = 0; x < bag.size();x++) {
		if (bag[x].second == 0) {
			std::cout << bag.size() << "\n";
			//bag.erase(bag.begin()+x);
			std::cout << bag.size() << "\n";
		}
		if (bag[x].first == _itemID) {
			bag[x].second -= 1;
		}
	}
}

void Inventory::showInventory() {
	for (int x = 0; x < bag.size();x++)
		itemsStack[x]->setString(std::to_string(bag[x].second));
	//std::cout << "Show number tems in bag: " << bag.size() << "\n";
}

//int Inventory::bagSize() {
//	return bag.size();
//}

void Inventory::drawInventory(sf::RenderWindow & _window) {
	//BAG SLOTS BACKGROUND
	for (auto& z : bagSlots) {
		_window.draw(*z);
	}

	for (auto& s : itemsStack) {
		if (s->getString() != '0')
			_window.draw(*s);
	}

	//ITEMS IN SLOTS
	for (auto& i : bag) {
		getItem<Items>(i.first)->itemSetScale(1, 1);
		getItem<Items>(i.first)->itemIconDraw(_window);
	}		

		
}
