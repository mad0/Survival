#include "Map.h"
#include <iostream>
#include <SFML\Graphics.hpp>


Map::Map(const std::string& TextureFile, sf::Vector2f Wsize) : TextureFile(TextureFile), Wsize(Wsize){
	loadX, loadY = 0;
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";
}

void Map::LoadTile(const std::vector<std::vector<int>>& Load, int loadX, int loadY) {
	std::cout<<Load.size();
	wierzcholki.setPrimitiveType(sf::Quads);
	wierzcholki.resize(10*10*4);
	//sf::Vertex* quad = &wierzcholki
	int r = 0;
		for (int x = 0; x < 10; x++) 
			for (int y = 0; y < 10; y++) {
				sf::Vertex* quad = &wierzcholki[(x+y*10)*4];
				quad[0].position = sf::Vector2f(x*32, y*32);
				quad[1].position = sf::Vector2f((x+1)*32, y*32);
				quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
				quad[3].position = sf::Vector2f(x*32, (y + 1) * 32);

				quad[0].texCoords = sf::Vector2f(0, 0);
				quad[1].texCoords = sf::Vector2f(32, 0);
				quad[2].texCoords = sf::Vector2f(32, 32);
				quad[3].texCoords = sf::Vector2f(0, 32);
				/*TileMap.push_back(std::make_unique<sf::Sprite>(_Texture, sf::IntRect(Load[y][x] * 32, 0, 32, 32)));
				TileMap[r]->setPosition(x * 32, y * 32);
				r++;*/
			}
}

void Map::draw(sf::RenderWindow& okno) {
	
	
	//for (int z = 0; z < 100; z++) {
		okno.draw(wierzcholki, &_Texture);
		//std::cout << TileMap[z]->getPosition().x << "\n";
		//okno.draw(*TileMap[z]);
	//}
		
}