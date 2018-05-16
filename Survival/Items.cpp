#include "Items.h"
#include <iostream>

Items::Items(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName) : itemID(_itemID), itemType(_itemType), iconFile(_iconFile),  itemName(_itemName) {
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
Weapons::Weapons(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName,  int _Ldmg, int _Hdmg) : Items(_itemID, _itemType, _iconFile, _itemName), Ldmg(_Ldmg), Hdmg(_Hdmg) {
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


////////////////////////////            CONSUMABLE      //////////////////////////////
int Consumable::getMinHP() {
	return minHP;
}

int Consumable::getMaxHP() {
	return maxHP;
}

void Consumable::setMinHP(int _minHP) {
	this->minHP = _minHP;
}

void Consumable::setMaxHP(int _maxHP) {
	this->maxHP = _maxHP;
}

Consumable::Consumable(int _itemID, ItemType _itemType, std::string _iconFile, const std::string & _itemName,  int _maxHP, int _minHP) :Items(_itemID, _itemType, _iconFile, _itemName), minHP(_minHP), maxHP(_maxHP) {
	std::cout << "Tworze consumable...\n";
}

Consumable::~Consumable() {
	std::cout << "Consumable...\n";
}
