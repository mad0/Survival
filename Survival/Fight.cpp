#include "Fight.h"
#include "Character.h"

Fight::Fight(Character *_player, Character *_enemy) : player(_player), enemy(_enemy){
	std::cout << "FIGHT START!\n";
	enemy->setHP(200);
}

Fight::~Fight() {
	std::cout << "FIGHT END!\n";
}
