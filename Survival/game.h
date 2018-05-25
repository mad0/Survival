#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "GameState.h"
#include "Map.h"
#include "Character.h"
#include "Inventory.h"
#include "Fight.h"
#include "GUI.h"

class Game : public GameState {
private:
	enum Directions { UP, DOWN, LEFT, RIGHT };
	GUI hud;
	sf::Text gui[3];
	std::string guiStr[4];
	sf::Font font;
	Inventory *bag;
	Weapons *weapon;
	bool inv;
	bool fight;
	sf::Vector2f Wsize;
	std::unique_ptr<Map> map;
	bool coll;
	void movePlayer(Directions);
	std::vector<Character*> enemy;
	void playerDirection(int x, int y);
	//std::unique_ptr<Character> p1;
	//std::unique_ptr<Character> crab;
	Character *p1;
public:
	void LoadMap();
	void fighto();
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
