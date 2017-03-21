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
	std::cout << "Rozmiar: " << Load.size()<<"\n";
	int r = 0;
	vertex.setPrimitiveType(sf::Quads);
	vertex.resize(2*(10 * 10 * 4));
	for (auto& coords : Load) {
		std::cout << coords.second.size() << "\n";
		for (int y = 0; y < 10; y++)
			for (int x = 0; x < 10; x++) {
				sf::Vertex* quad = &vertex[(x + y * 10) * 4];
				int tileNumber = coords.second[x][]

				// znalezienie jego pozycji na tileset
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				quad[0].position = sf::Vector2f(x * 32, y * 32);
				quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
				quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
				quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);
				std::cout << coords.second[x][y] << "\n";
				quad[0].texCoords = sf::Vector2f(coords.second[x][y]*32, 0);
				quad[1].texCoords = sf::Vector2f((coords.second[x][y]) * 32, 0);
				quad[2].texCoords = sf::Vector2f(coords.second[x][y] * 32, coords.second[x][y] * 32);
				quad[3].texCoords = sf::Vector2f(coords.second[x][y]+1, 32);
			}
	}
}

void Map::draw(sf::RenderWindow& okno) {
	//for (int z = 0; z < 200; z++) {
	//for (auto& p: TileMap)
		//okno.draw(*p);
	okno.draw(vertex);
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