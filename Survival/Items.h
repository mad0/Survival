#pragma once
#include <iostream>
#include <string>

class Items {
private:
	std::string name;
	int Ldmg;
	int Hdmg;
public:
	std::string Sname();
	int SLdmg();
	int SHdmg();
	Items(const std::string&, int, int);
	~Items();
};
