#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class Items  {
public:
	enum ItemType {
		WEAPON,
		ARMOR,
		FOOD,
		POTION
	};
	std::string getName() const;
	int getID() const;
	ItemType getItemType() const;
	void itemIcon(sf::Vector2f _pos);
	void itemIconDraw(sf::RenderWindow& _window);
	void itemSetScale(float _scaleX, float _scaleY);
	Items(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName);
	virtual void tooltip();
	virtual ~Items();
protected:
	ItemType itemType;
	int itemID;
	std::string iconFile;
	std::string itemName;
	sf::Sprite sprite;
	sf::Texture texture;
};

class Weapons : public Items {
protected:
	int Ldmg;
	int Hdmg;
public:
	int getDamage();
	int getLdmg();
	int getHdmg();
	void setLdmg(int _Ldmg);
	void setHdmg(int _Hdmg);
	Weapons(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName,  int _Ldmg, int _Hdmg);
	virtual ~Weapons();
};

class Potions : public Items {
private:
	int minHP;
	int maxHP;
public:
	int getMinHP();
	int getMaxHP();
	void setMinHP(int _minHP);
	void setMaxHP(int _maxHP);
	Potions(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName, int _minHP, int _maxHP);
	virtual ~Potions();
};

class Food : public Items {
private:
	int maxHP;
public:
	int getMaxHP();
	void setMaxHP(int _maxHP);
	Food(int _itemID, ItemType _itemType, std::string _iconFile, const std::string& _itemName, int _maxHP);
	virtual ~Food();
};