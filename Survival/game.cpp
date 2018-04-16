#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	coll = false;
	engine = gra;
	Wsize = sf::Vector2f(engine->window.getSize());
	map = std::make_unique<Map>(engine->window, "gfx/maps.gif", Wsize);
	LoadMap();
	p1 = std::make_unique<Character>(128, engine->window);
	p1->setPosition(6*32, 2*32);
	weaponInvent.push_back(Weapons(Items::WEAPON, "gfx/sword1.png", "Iron Dagger", 1, 4, 10));
	std::cout << "ADRES VECTORA: " << &weaponInvent << "\n";
	//consumableInvent.push_back(std::make_unique<Consumable>(Items::FOOD, "gfx/sword1.png", "Simple Potion", 2, 5, 6));
	//bag.addItem(new Weapons(Weapons::WEAPON, "gfx/sword1.png", "Iron Dagger", 1, 4, 10), 0);
	//bag.addItem(new Consumable(Items::FOOD, "gfx/sword1.png", "Simple Potion", 2, 5, 6), 1);
	bag.addToInventory(weaponInvent);
	//bag.addToInventory(weaponInvent[0]->getItemType(), weaponInvent[0]->getID(), weaponInvent[0]->getName(), 0);
	//bag.addToInventory(consumableInvent[0]->getItemType(), consumableInvent[0]->getID(), consumableInvent[0]->getName(), 1);
	//items.push_back(new Weapons("gfx/sword1.png", "Iron Dagger", 1, 4));
	//items.push_back(new Potions("gfx/potion.png", "Simple Potion", 5, 11));
	//assert(nullptr != b);
	//static_cast<Weapons*>(items[0])->getHdmg();
//	std::cout << "Inventory size: "<<items.size()<<"\n";
	//items[1]->
	
	
	//weapon[0]->itemIcon(Wsize);
	//std::cout<<typeid (items[1]).name();
	//bag.inventory.push_back()
	font.loadFromFile("fonts/Vecna.otf");
	guiStr[0] = "Health points ";
	guiStr[1] = "Weapon: ";
	guiStr[2] = "Damage: ";
	for (int x=0;x<3;x++) {
		gui[x].setFont(font);
		gui[x].setCharacterSize(25);
	}
	//HP
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->show_hp()));
	gui[0].setPosition(50, Wsize.y-100);
	//Nazwa broni
	//gui[1].setString(guiStr[1] + weapon->getName());
	gui[1].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 100);
	//Obrazenia
	//gui[2].setString(guiStr[2] + std::to_string(weapon->getLdmg()) + "-" + std::to_string(weapon->getHdmg()));
	gui[2].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 75);
	std::cout << "Wchodze z MENU do GRY\n";
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(engine->window));
	while (engine->window.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			engine->window.close();
		//if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Escape)
		//	engine->del();
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Up)
			movePlayer(Game::UP);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Down)
			movePlayer(Game::DOWN);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Left)
			movePlayer(Game::LEFT);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Right)
			movePlayer(Game::RIGHT);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Space) {
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::I) {
			bag.showInventory();
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::D) {
			//bag.delFromInventory(0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		engine->delState();

}

void Game::movePlayer(Directions direct) {
	switch (direct) {
		case Game::UP:
			std::cout << "UP\n";
			playerDirection(0, -32);
			break;
		case Game::DOWN:
			std::cout << "DOWN\n";
			playerDirection(0, 32);
			break;
		case Game::LEFT:
			std::cout << "LEFT\n";
			playerDirection(-32, 0);
			break;
		case Game::RIGHT :
			std::cout << "RIGHT\n";
			playerDirection(32, 0);
			break;
	}
	/*
	if (map->collision(int(nextPos.x/32),  int(nextPos.y/32), p1->getBounds())) {
		
		std::cout << "PLAYER: "<<p1->getBounds().left << " " << p1->getBounds().top << "\n";
		std::cout << "KOLIZJA!\n";
		//p1->setPosition(actPos.x-x, actPos.y);
		//p1->getPosition().x / 32 << " " << p1->getPosition().y / 32
		//std::cout << p1->getPosition().x << " " << p1->getPosition().y << "\n";
		*/

	}

void Game::playerDirection(int x, int y) {
	sf::Vector2f actPos(p1->getPosition().x/32, p1->getPosition().y/32);
	sf::Vector2f nextPos(actPos.x + (x/32), actPos.y + (y/32));
	if (map->collision(nextPos.x, nextPos.y))
		std::cout << "KOLIZJA!\n";
	else
		p1->move(x, y);
	if (map->Interaction(nextPos.x, nextPos.y)) {
		std::cout << "INTERAKCJA!\n";
		std::cout << p1->getPosition().x / 32 << " : " << p1->getPosition().y / 32 << "\n";
	}
		
		
}

void Game::draw() {
	engine->window.clear();
	for (auto x: gui)
		engine->window.draw(x);
	//weapon->itemIconDraw(engine->window);
	map->draw();
	p1->draw();
}

void Game::update() {
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->show_hp()));
	//gui[1].setString(guiStr[1] + weapon->getName());
	//gui[2].setString(guiStr[2] + std::to_string(weapon->getLdmg()) + "-" + std::to_string(weapon->getHdmg()));
	//sf::Vector2f kafel(p1->getPosition().x , p1->getPosition().y);
	//std::cout << "Aktualny kafel: " << int(kafel.x/32) << " " << int(kafel.y/32) << "\n";
	//coll = map->collision(*p1);
	//std::cout << p1->getPosition().x << " " << p1->getPosition().y  << "\n";
	//std::cout << kafel.x + (p1->getBounds().height / 2) + 1<<"\n";
	
}

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
}


void Game::LoadMap() {
	std::vector<int> Load = {
		0,0,0,0,0,39,39,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,39,0,0,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,39,39,39,39,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,39,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,39,39,0,39,39,39,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,39,39,39,39,39,39,39,49,39,0,0,0,0,0,0,0,0,0,
		0,39,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,51,0,0,0,0,39,0,0,39,0,0,0,0,0,0,0,0,0,
		0,39,0,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,39,39,0,0,39,39,0,39,0,0,0,0,39,39,51,39,39,
		0,39,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0,0,39,0,0,0,0,39,0,0,0,39,
		0,39,0,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,0,39,0,0,0,0,0,39,0,0,0,0,39,0,0,0,39,
		0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,39,39,0,39,39,39,39,0,0,0,0,39,39,0,39,39,
		0,39,39,39,39,39,39,39,39,39,39,39,0,39,39,39,39,39,39,39,39,0,39,0,0,39,0,39,0,0,0,0,0,0,0,0,39,0,39,0,
		0,0,0,0,0,0,0,0,0,0,0,39,0,39,0,0,0,0,0,0,39,0,39,0,0,39,0,39,0,0,39,39,39,39,39,39,39,0,39,0,
		0,0,0,0,0,0,0,39,39,39,39,39,0,39,0,0,0,0,0,0,39,0,39,39,39,39,0,39,39,39,39,0,0,0,0,0,0,0,39,0,
		0,0,0,0,0,0,0,39,0,0,0,0,0,39,0,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,39,39,39,39,39,39,0,
		0,0,0,0,0,0,0,39,0,39,39,39,39,39,0,0,0,0,0,0,39,39,39,39,39,39,39,39,39,39,39,39,0,39,0,0,0,0,0,0,
		0,0,0,0,0,0,0,39,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,39,0,0,0,39,39,39,
		39,39,39,39,39,39,39,39,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,39,39,39,39,39,0,63,
		19,0,0,0,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0,0,0,0,39,
		39,39,39,39,39,39,39,39,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,39,39,39,39,39,39,39,39 };
	std::vector<int> Load2 = {
		0,0,0,0,73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,73,73,73,73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,73,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		73,73,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,73,73,73,73,73,73,73,73,73,73,73,0,0,0,0,0,0,0,0,
		73,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,
		73,0,0,0,0,73,73,73,73,73,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,73,0,0,73,73,73,73,73,73,
		73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,73,0,0,73,0,0,0,0,0,
		73,0,0,0,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,0,0,0,0,0,0,0,73,0,0,73,0,0,0,0,0,
		73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,73,0,0,73,0,0,0,0,0,
		73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,73,0,0,73,0,0,0,0,0,
		73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,73,0,0,0,73,73,73,73,73,73,73,73,0,0,0,73,
		73,73,73,73,73,73,73,73,73,73,73,0,0,0,73,73,73,73,73,73,0,0,0,73,73,0,0,0,73,73,0,0,0,0,0,0,0,0,0,73,
		0,0,0,0,0,0,73,0,0,0,0,0,0,0,73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,
		0,0,0,0,0,0,73,0,0,0,0,0,0,0,73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,
		0,0,0,0,0,0,73,0,0,0,0,0,0,0,73,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,73,73,73,73,73,
		73,73,73,73,73,73,73,0,0,0,73,73,73,73,73,0,0,0,0,73,73,73,73,73,73,73,73,73,73,73,73,0,0,0,73,73,73,0,0,0,
		0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0 };
	std::map<std::string, const std::vector<int>> LoadV = {
		std::make_pair("Layer1", Load),
		std::make_pair("Layer2", Load2)
	};
	map->LoadTile(LoadV);
	//map->drawMap();
}