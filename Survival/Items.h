#pragma once
#include <iostream>
#include <string>

class Items {
private:
	std::string name;
public:
	std::string getName();
	Items(const std::string&);
	~Items();
};


class Weapons : public Items {
private:
	int Ldmg;
	int Hdmg;
public:
	Weapons(const std::string&, int, int);
	~Weapons();
	int getLdmg();
	int getHdmg();
};