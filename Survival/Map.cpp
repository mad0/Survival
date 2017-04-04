#include "Map.h"
#include <iostream>
#include <SFML\Graphics.hpp>


Map::Map(sf::RenderWindow& okno, const std::string& TextureFile, sf::Vector2f Wsize) : okno(okno), TextureFile(TextureFile), Wsize(Wsize){
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";
}

void Map::LoadTile(const std::map<std::string, const std::vector<int>>& Load) {
	std::cout << "Rozmiar: " << Load.size() << "\n";
	int Layer = 0;
	for (auto& coords : Load) {
		vertex[Layer].setPrimitiveType(sf::Quads);
		vertex[Layer].resize(10 * 10 * 4);
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				sf::Vertex* quad = &vertex[Layer][(x + y * 10) * 4];
				//std::cout << "x=" << x << "y=" << y << " suma=" << x + y * 10 << "\n";
				int  tile = coords.second[x + y * 10];
				CollisionMap(tile);
				quad[0].position = sf::Vector2f(x * 32, y * 32);
				quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
				quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
				quad[3].position = sf::Vector2f(x * 32, (y + 1) *32);
				//std::cout << "Typ kafelka: " << tile<<"\n";
				quad[0].texCoords = sf::Vector2f(tile * 32, 0);
				quad[1].texCoords = sf::Vector2f((tile + 1) * 32, 0);
				quad[2].texCoords = sf::Vector2f((tile + 1) * 32, 32);
				quad[3].texCoords = sf::Vector2f(tile * 32, 32);
			}
		}
		Layer++;
	}
}

void Map::CollisionMap(int tile) {
	TileProp tileprop;
	switch (tile) {
		case Map::EMPTY:
			tileprop.collision = false;
			tileprop.interaction = false;
			break;
		case Map::STONE:
			std::cout << "MUR\n";
			tileprop.collision = true;
			tileprop.interaction = false;
			break;
		case Map::GRASS:
			tileprop.collision = false;
			tileprop.interaction = false;
			break;
		case Map::MUSHROOM:
			tileprop.collision = true;
			tileprop.interaction = true;
			break;
		default:
			break;
	}
	PropMap.insert(std::make_pair(tile, tileprop));
}

void Map::draw() {
	for (auto& p: vertex)
		okno.draw(p, &_Texture);
}

bool Map::collision(Character& player) {
	sf::Vector2f curPos = player.getPosition();
	//std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
	//if (TileMap[11]->getGlobalBounds().intersects(player.getBounds()))
	//	return true;
	return false;
	//if (TileMap[1]->getGlobalBounds().intersects(player.getPosition()))
	//	std::cout << "KAFEL11111111111\n";
}