#include "Items.h"

Items::Items(const std::string& name, int Ldmg, int Hdmg) : name(name), Ldmg(Ldmg), Hdmg(Hdmg){
	
}


Items::~Items() {

}

std::string Items::Sname() {
	return name;
}

int Items::SLdmg() {
	return Ldmg;
}

int Items::SHdmg() {
	return Hdmg;
}