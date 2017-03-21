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

void Map::LoadTile(const std::map<std::string, const std::vector<std::vector<int>>>& Load, int loadX, int loadY) {
	std::cout <<"Rozmiar: "<< Load.size();
	wierzcholki.setPrimitiveType(sf::Quads);
	wierzcholki.resize(4);
	//sf::Vertex* quad = &wierzcholki
	int r = 0;
	for (auto& coords : Load)
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				/*sf::Vertex* quad = &wierzcholki[(x+y*10)*4];
				quad[0].position = sf::Vector2f(x*32, y*32);
				quad[1].position = sf::Vector2f((x+1)*32, y*32);
				quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
				quad[3].position = sf::Vector2f(x*32, (y + 1) * 32);

				quad[0].texCoords = sf::Vector2f(0, 0);
				quad[1].texCoords = sf::Vector2f(32, 0);
				quad[2].texCoords = sf::Vector2f(32, 32);
				quad[3].texCoords = sf::Vector2f(0, 32);*/
				TileMap.emplace_back(std::make_unique<sf::Sprite>(_Texture, sf::IntRect(coords.second[y][x] * 32, 0, 32, 32)));
				TileMap[r]->setPosition(x * 32, y * 32);
				r++;
			}
		}
			
		/*sf::Vertex* quad = &wierzcholki[0];
		quad[0].position = sf::Vector2f(32,32);
		quad[1].position = sf::Vector2f(64,32);
		quad[2].position = sf::Vector2f(64,64);
		quad[3].position = sf::Vector2f(32,64);
		quad[0].texCoords = sf::Vector2f(64,0);
		quad[1].texCoords = sf::Vector2f(96,0);
		quad[2].texCoords = sf::Vector2f(96, 32);
		quad[3].texCoords = sf::Vector2f(64, 32);*/
}

void Map::draw(sf::RenderWindow& okno) {
	
	
	for (int z = 0; z < 200; z++) {
		//okno.draw(wierzcholki, &_Texture);
		//std::cout << TileMap[z]->getPosition().x << "\n";
		okno.draw(*TileMap[z]);
	}
	//okno.draw(wierzcholki, &_Texture);
		
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