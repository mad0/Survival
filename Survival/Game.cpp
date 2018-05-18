#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	itemsDB.emplace(std::pair<int, Items*>(1, new Potions(1, Items::POTION, "gfx/potion.png", "Simple potion", 5, 11)));
	itemsDB.emplace(std::pair<int, Items*>(2, new Food(2, Items::FOOD, "gfx/banana.png", "Banana", 12)));
	itemsDB.emplace(std::pair<int, Items*>(3, new Weapons(3, Items::WEAPON, "gfx/dagger.png", "Simple Dagger", 6, 12)));
	std::cout << "ItemsDB size: " << itemsDB.size() << "\n";
	coll = false;
	inv = false;
	fight = false;
	engine = gra;
	Wsize = sf::Vector2f(engine->window.getSize());
	map = std::make_unique<Map>(engine->window, "gfx/maps.gif", Wsize);
	LoadMap();
	p1 = new Character("gfx/player.png", 128);
	p1->setPosition(6 * 32, 2 * 32);
	weapon = new Weapons(10, Items::WEAPON, "gfx/dagger.png", "Simple iron dagger", 6, 10);
	p1->equipWeapon(weapon);
	enemy.emplace_back(new Character("gfx/m1.png", 200));
	enemy[0]->setPosition(4 * 32, 3 * 32);
	enemy.emplace_back(new Character("gfx/m2.png", 200));
	enemy[1]->setPosition(5 * 32, 3 * 32);
	enemy.emplace_back(new Character("gfx/m2.png", 200));
	enemy[2]->setPosition(3 * 32, 4 * 32);
	//bag = new Inventory(5);
	//bag->addItem(new  Consumable(1, Items::POTION, "gfx/potion.png", "Simple potion", 5, 10));
	//bag->addItem(new  Consumable(1, Items::POTION, "gfx/potion.png", "Simple potion", 5, 10));
	//bag->addItem(new  Consumable(1, Items::POTION, "gfx/potion.png", "Simple potion", 5, 10));
	//bag->addItem(new  Consumable(2, Items::FOOD, "gfx/banana.png", "Banana", 4, 8));
	//bag->addItem(new  Consumable(2, Items::FOOD, "gfx/banana.png", "Banana", 4, 8));
	font.loadFromFile("fonts/Vecna.otf");
	guiStr[0] = "Health points ";
	guiStr[1] = "Weapon: ";
	guiStr[2] = "Damage: ";
	for (int x=0;x<3;x++) {
		gui[x].setFont(font);
		gui[x].setCharacterSize(25);
	}
	//HP
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->getmaxHp()));
	gui[0].setPosition(50, Wsize.y-100);
	//Nazwa broni
	gui[1].setString(guiStr[1] + weapon->getName());
	gui[1].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 100);
	//Obrazenia
	gui[2].setString(guiStr[2] + std::to_string(weapon->getLdmg()) + "-" + std::to_string(weapon->getHdmg()));
	gui[2].setPosition(gui[0].getGlobalBounds().width + 100, Wsize.y - 75);
	std::cout << "Wchodze z MENU do GRY\n";
	
	if (itemsDB.at(1)->getItemType() == Items::POTION) {
		Potions *pot = dynamic_cast<Potions*>(itemsDB.at(1));
		pot->setMaxHP(100);
		std::cout << pot->getMaxHP() << "nowe hp";
	}
}

void Game::inputs() {
	sf::Event zdarz;
	sf::Vector2f mouse(sf::Mouse::getPosition(engine->window));
	while (engine->window.pollEvent(zdarz)) {
		if (zdarz.type == sf::Event::Closed)
			engine->window.close();
		//if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code =damage= sf::Keyboard::Escape)
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
			bag->showInventory();
			if (inv)
				inv = false;
			else 
				inv = true;	
		}
		if (zdarz.type == sf::Event::MouseButtonPressed && zdarz.key.code == sf::Mouse::Left) {
			std::cout << p1->getWeapon()->getName();
		
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

void Game::update() {
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->getHp()));
	gui[1].setString(guiStr[1] + p1->getWeapon()->getName());
	gui[2].setString(guiStr[2] + std::to_string(p1->getWeapon()->getLdmg()) + "-" + std::to_string(p1->getWeapon()->getHdmg()));
	p1->getWeapon()->itemIcon(sf::Vector2f(Wsize.x / 2 - 64, Wsize.y - 150));
	fighto();

	//sf::Vector2f kafel(p1->getPosition().x , p1->getPosition().y);
	//std::cout << "Aktualny kafel: " << int(kafel.x/32) << " " << int(kafel.y/32) << "\n";
	//coll = map->collision(*p1);
	//std::cout << p1->getPosition().x << " " << p1->getPosition().y  << "\n";
	//std::cout << kafel.x + (p1->getBounds().height / 2) + 1<<"\n";
	
}
void Game::draw() {
	engine->window.clear();
	map->draw();
	for (auto x: gui)
		engine->window.draw(x);
	p1->getWeapon()->itemIconDraw(engine->window);
	for (auto& e:enemy) {
		if (e->isAlive())
			e->draw(engine->window);
	}

	p1->draw(engine->window);
	if (inv)
		bag->drawInventory(engine->window);
}

void Game::fighto() {
	if (enemy.size() > 0) {
		for (int x=0;x<enemy.size();x++) {
			if (p1->collisionBox().intersects(enemy[x]->collisionBox())) {
				std::cout << x << "ZNALAZLEM\n";
				if (enemy[x]->isAlive()) {
					Fight fight1(p1, enemy[x]);
				}
				if (!enemy[x]->isAlive()) {
					delete enemy[x];
					enemy.erase(enemy.begin() + x);
					std::cout << "ENEMy " << enemy.size() << "\n";
				}
			}
		}
	}
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

Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
	delete bag;
	delete weapon;
	if (enemy.size() > 0) {
		for (auto& e : enemy) {
			delete e;
		}
	enemy.clear();
	}
	delete p1;
}