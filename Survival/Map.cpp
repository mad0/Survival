#include "Map.h"
#include <iostream>


Map::Map(const std::string& TextureFile) : TextureFile(TextureFile) {
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
	 

}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";

}

void Map::LoadTile() {
	int TileSet[10][10] = {
		{ 1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,1,0,0,0,0,0,0,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1 }
	};
	int r = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (TileSet[x][y] > 0) {
				std::cout << r << " pelny \n";
				TileMap.push_back(std::make_unique<sf::Sprite>());
				TileMap[r]->setTexture(_Texture);
				TileMap[r]->setPosition(x * 32, y * 32);
				r++;
			}
			else {
				std::cout << r << " pusty \n";
				TileMap.push_back(std::make_unique<sf::Sprite>());
				r++;
			}
		}
		
	}
	std::cout << TileMap.size();
}

void Map::draw(sf::RenderWindow& okno) {
	
	
	for (int z = 0; z < 100; z++) {
		//std::cout << TileMap[z]->getPosition().x << "\n";
		okno.draw(*TileMap[z]);
	}
		
}