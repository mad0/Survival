#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class Items  {
private:
	
public:
	std::string getName();
	Items(const std::string&, const std::string&);
	~Items();
protected:
	std::string file;
	std::string name;
	sf::Sprite icon;
	sf::Texture texture;
};


class Weapons : public Items {
private:
	int Ldmg;
	int Hdmg;
public:
	Weapons(const std::string&, const std::string&, int, int);
	~Weapons();
	int getLdmg();
	int getHdmg();
	void newWeapon();
	void Icon(sf::Vector2f);
	void IconDraw(sf::RenderWindow&);
};