#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Weapons;

class Character {
private:
	int hp;
	std::string Iname;
	sf::Sprite Char;
	sf::Texture CharIdle;
	struct characterSlots {
		Weapons* hand;
	};
	characterSlots Slots;
	//Items jeden;
	sf::RenderWindow& okno;
	sf::View gra;
public:
	Character(int hp, sf::RenderWindow& okno);
	~Character();
	int show_hp();
	int bagSize();
	void move(short, short);
	void draw();
	void anim(int, int);
	void setWeapon(Weapons* _weapon);
	Weapons* getWeapon();
	//sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void setPosition(float, float);
};

