#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "Map.h"
#include "Character.h"
#include "Items.h"
#include "Inventory.h"

class Game : public GameState {
private:
	enum Directions { UP, DOWN, LEFT, RIGHT };
	sf::Text gui[3];
	std::string guiStr[4];
	sf::Font font;
	Inventory *bag;
	Weapons *weapon;
	Consumable *food;
	sf::Vector2f Wsize;
	std::unique_ptr<Map> map;
	bool coll;
	void movePlayer(Directions);
	void playerDirection(int x, int y);
	std::unique_ptr<Character> p1;
public:
	void LoadMap();
	//Map map1;
	//std::unique_ptr<GUI> ui;
	//std::unique_ptr<GUI> quests;
	//std::unique_ptr<GUI> map;
	//sf::Vector2f Wsize;
	virtual void inputs();
	virtual void update();
	virtual void draw();
	Game(Engine* gra);
	~Game();
	
};
