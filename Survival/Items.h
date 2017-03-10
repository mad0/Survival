#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class Items  {
private:
	
	std::string file;
	sf::Sprite icon;
	sf::Texture texture;
public:
	std::string getName();
	Items(const std::string&, const std::string&);
	~Items();
protected:
	std::string name;
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
};