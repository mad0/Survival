#include "Items.h"
#include <iostream>

Items::Items(ItemType _itemType, std::string _iconFile, const std::string& _itemName) : itemType(_itemType), iconFile(_iconFile),  itemName(_itemName) {
	std::cout<<"Tworze item: ";
}

void Items::tooltip()
{
}

Items::~Items() {
	std::cout << "Niszcze item: ";
}

void Items::itemIcon(sf::Vector2f _pos) {
	texture.loadFromFile(iconFile);
	sprite.setTexture(texture);
	sprite.setPosition(_pos);
}

void Items::itemIconDraw(sf::RenderWindow & _window) {
	_window.draw(sprite);
}

void Items::itemSetScale(float _scaleX, float _scaleY) {
	sprite.setScale(_scaleX, _scaleY);
}

std::string Items::getName() const {
	return itemName;
}

int Items::getID() const {
	return itemID;
}

Items::ItemType Items::getItemType() const {
	return itemType;
}


/////////////////////////////             Weapons        /////////////////////////////
Weapons::Weapons(ItemType _itemType, std::string _iconFile, const std::string& _itemName,  int _Ldmg, int _Hdmg) : Items(_itemType, _iconFile, _itemName), Ldmg(_Ldmg), Hdmg(_Hdmg) {
	std::cout << "Tworze bron.\n";
}

Weapons::~Weapons() {
	std::cout << "Bron...\n";
}


int Weapons::getDamage()
{
	return 0;
}

int Weapons::getLdmg() {
	return Ldmg;
}

int Weapons::getHdmg() {
	return Hdmg;
}

void Weapons::setLdmg(int _Ldmg) {
	this->Ldmg = _Ldmg;
}

void Weapons::setHdmg(int _Hdmg) {
	this->Hdmg = _Hdmg;
}

////////////////////////////            Potions      //////////////////////////////
int Potions::getMaxHP() {
	return maxHP;
}

void Potions::setMaxHP(int _maxHP) {
	this->maxHP = _maxHP;
}

Potions::Potions(ItemType _itemType, std::string _iconFile, const std::string & _itemName, int _minHP, int _maxHP) :Items(_itemType, _iconFile, _itemName), minHP(_minHP), maxHP(_maxHP) {
	std::cout << "Tworze Potions...\n"; }

Potions::~Potions() {
	std::cout << "Potions...\n"; }


////////////////////////////           FOOD      //////////////////////////////
int Food::getMaxHP() {
	return maxHP;
}

void Food::setMaxHP(int _maxHP) {
	this->maxHP = _maxHP;
}

Food::Food(ItemType _itemType, std::string _iconFile, const std::string & _itemName, int _maxHP) :Items(_itemType, _iconFile, _itemName), maxHP(_maxHP) {
	std::cout << "Tworze FOOD...\n";
}

Food::~Food() {
	std::cout << "FOOD...\n";
}
