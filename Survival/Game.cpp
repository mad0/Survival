#include "Game.h"
#include <iostream>

Game::Game(Engine* gra) {
	coll = false;
	inv = false;
	fight = false;
	engine = gra;
	p1 = std::make_unique<Character>("gfx/3.png", 1280);
	p1->setPosition(6 * 32, 2 * 32);
	weapon = new Weapons(Items::WEAPON, "gfx/dagger.png", "Simple iron dagger", 6, 10);
	p1->equipWeapon(weapon);
	//hud = new GUI(p1);
	Wsize = sf::Vector2f(engine->window.getSize());
	map = std::make_unique<Map>(engine->window, "gfx/BeachTileset.png", Wsize);
	//weapon = dynamic_cast<Weapons*>(itemsDB.at(3));
	//weapon = getItem<Weapons>(3);
	//enemy.emplace_back(new Character("gfx/m1.png", 200));
	//enemy[0]->setPosition(4 * 32, 3 * 32);
	//enemy.emplace_back(new Character("gfx/m2.png", 200));
	//enemy[1]->setPosition(5 * 32, 3 * 32);
	//enemy.emplace_back(new Character("gfx/m2.png", 200));
	//enemy[2]->setPosition(3 * 32, 4 * 32);
	//bag = new Inventory(5);
	//bag->addToBag(1, 20);
	//bag->addToBag(1, 15);
	//bag->addToBag(1, 30);
	//bag->addToBag(2, 4);
	//bag->addToBag(1, 3);
	//bag->addToBag(3, 2);

	font.loadFromFile("fonts/Vecna.otf");
	guiStr[0] = "Health points ";
	guiStr[1] = "Weapon: ";
	guiStr[2] = "Damage: ";
	for (int x=0;x<3;x++) {
		gui[x].setFont(font);
		gui[x].setFillColor(sf::Color::White);
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
	
	//if (itemsDB.at(1)->getItemType() == Items::POTION) {
	//	Potions *pot = dynamic_cast<Potions*>(itemsDB.at(1));
	//	pot->setMaxHP(100);
	//	std::cout << pot->getMaxHP() << "nowe hp";
	//}
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
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::D)
			p1->setHP(-10);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Left)
			movePlayer(Game::LEFT);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Right)
			movePlayer(Game::RIGHT);
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::Space) {
			//bag->addToBag(1, 1);
			
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::I) {
			//bag->showInventory();
			//if (inv)
			//	inv = false;
			//else 
			//	inv = true;	
		}
		if (zdarz.type == sf::Event::MouseButtonPressed && zdarz.key.code == sf::Mouse::Left) {
			std::cout << p1->getWeapon()->getName();
		
		}
		if (zdarz.type == sf::Event::KeyPressed && zdarz.key.code == sf::Keyboard::D) {
			//bag->delItem(1);
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
	gui[0].setString(guiStr[0] + "\n      " + std::to_string(p1->getHp())+"/"+std::to_string(p1->getmaxHp()));
	gui[1].setString(guiStr[1] + p1->getWeapon()->getName());
	gui[2].setString(guiStr[2] + std::to_string(p1->getWeapon()->getLdmg()) + "-" + std::to_string(p1->getWeapon()->getHdmg()));
	p1->getWeapon()->itemIcon(sf::Vector2f(Wsize.x / 2 - 64, Wsize.y - 150));
	fighto();
	//bag->showInventory();
	//hud->update();
	//sf::Vector2f kafel(p1->getPosition().x , p1->getPosition().y);
	//std::cout << "Aktualny kafel: " << int(kafel.x/32) << " " << int(kafel.y/32) << "\n";
	//coll = map->collision(*p1);
	//std::cout << p1->getPosition().x << " " << p1->getPosition().y  << "\n";
	//std::cout << kafel.x + (p1->getBounds().height / 2) + 1<<"\n";
	
}
void Game::draw() {
	engine->window.clear(sf::Color::White);
	//map->draw();
	//hud->draw(engine->window);
	for (auto x : gui)
		engine->window.draw(x);
	p1->getWeapon()->itemIconDraw(engine->window);
	//for (auto& e:enemy) {
	//	if (e->isAlive())
	//		e->draw(engine->window);
	//}
	
	p1->draw(engine->window);
	//if (inv)
		//bag->drawInventory(engine->window);
}

void Game::fighto() {
	//if (enemy.size() > 0) {
	//	for (int x=0;x<enemy.size();x++) {
	//		if (p1->collisionBox().intersects(enemy[x]->collisionBox())) {
	//			std::cout << x << "ZNALAZLEM\n";
	//			if (enemy[x]->isAlive()) {
	//				Fight fight1(p1, enemy[x]);
	//			}
	//			if (!enemy[x]->isAlive()) {
	//				delete enemy[x];
	//				enemy.erase(enemy.begin() + x);
	//				std::cout << "ENEMy " << enemy.size() << "\n";
	//			}
	//		}
	//	}
	//}
}


Game::~Game() {
	std::cout << "Wychodze z GRY do MENU\n";
	//delete bag;
	delete weapon;
	//if (enemy.size() > 0) {
	//	for (auto& e : enemy) {
	//		delete e;
	//	}
	//enemy.clear();
	//}
	//delete p1;
	//delete hud;
}