#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Items.h"

class Character {
private:
	int hp;
	int maxHp;
	sf::Sprite charSprite;
	sf::Texture charTexture;
	//Items jeden;
	sf::RenderWindow& okno;
	sf::View gra;
public:
	struct characterSlots {
		Weapons* hand;
	};
	characterSlots Slots;
	Character(sf::RenderWindow& _okno, int _hp);
	~Character();
	int getHp();
	int getmaxHp();
	void move(short, short);
	void draw();
	//void anim(int, int);
	void equipWeapon(Weapons* _weapon);
	Weapons *getWeapon();
	//sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void setPosition(float, float);
};

