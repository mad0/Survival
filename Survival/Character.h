#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Items.h"

class Character {
private:
	struct characterSlots {
		Weapons* hand;
	};
	characterSlots slots;
	int hp;
	int maxHp;
	sf::Sprite charSprite;
	//Items jeden;
	//sf::View gra;
	sf::Texture charTexture;
public:
	Character(std::string _iconFile,  int _hp);
	~Character();
	int getHp();
	int getmaxHp();
	bool isAlive();
	void move(short, short);
	void draw(sf::RenderWindow & _okno);
	//void anim(int, int);
	void equipWeapon(Weapons* _weapon);
	void setHP(int _hp);
	void setMaxHP(int _hp);
	Weapons *getWeapon();
	//sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void setPosition(float, float);
	sf::FloatRect collisionBox();
};

