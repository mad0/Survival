#include "Map.h"
#include <iostream>
#include <SFML\Graphics.hpp>


Map::Map(const std::string& TextureFile, sf::Vector2f Wsize) : TextureFile(TextureFile), Wsize(Wsize){
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";
}

void Map::LoadTile(const std::map<std::string, const std::vector<std::vector<int>>>& Load) {
	//std::cout <<"Rozmiar: "<< Load.size()
	int r = 0;
	for (auto& coords : Load) {
		std::cout << coords.second.size() << "\n";
		for (int x = 0; x < coords.second.size(); x++) {
			for (int y = 0; y < coords.second.size(); y++) {
				TileMap.emplace_back(std::make_unique<sf::Sprite>(_Texture, sf::IntRect(coords.second[y][x] * 32, 0, 32, 32)));
				TileMap[r]->setPosition(x * 32, y * 32);
				r++;
			}
		}
	}
}

void Map::draw(sf::RenderWindow& okno) {
	//for (int z = 0; z < 200; z++) {
	for (auto& p: TileMap)
		okno.draw(*p);
}

bool Map::collision(Character& player) {
	sf::Vector2f curPos = player.getPosition();
	//std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
	if (TileMap[11]->getGlobalBounds().intersects(player.getBounds()))
		return true;
	return false;
	//if (TileMap[1]->getGlobalBounds().intersects(player.getPosition()))
	//	std::cout << "KAFEL11111111111\n";
}