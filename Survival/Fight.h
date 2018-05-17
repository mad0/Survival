#pragma once
#include <memory>

class Character;

class Fight {
	Character *player;
	Character *enemy;
public:
	Fight(Character *_player, Character *_enemy);
	~Fight();
};

