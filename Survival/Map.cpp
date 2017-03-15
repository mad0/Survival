#include "Map.h"
#include <iostream>


Map::Map(const std::string& TextureFile) : TextureFile(TextureFile) {
	_Texture.loadFromFile(TextureFile);
	 

}

Map::~Map(){
	

}

void Map::LoadTile() {
	
	
}

void Map::draw(sf::RenderWindow& okno) {
	int TileSet[10][10] = {
		{ 1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1 }
	};
	
	for (int z = 0; z < 100; z++) {
		//std::cout << TileMap[z]->getPosition().x << "\n";
		okno.draw(*TileMap[z]);
	}
		
}