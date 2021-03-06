#include "Map.h"
#include <iostream>
#include <SFML\Graphics.hpp>

Map::Map(sf::RenderWindow& okno, const std::string& TextureFile, sf::Vector2f Wsize) : okno(okno), TextureFile(TextureFile), Wsize(Wsize){
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
	PropMap.assign(15, std::vector<TileProp>(10));
	LoadMap();
}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";
}

void Map::LoadTile(const std::map<std::string, const std::vector<int>>& Load) {
	std::cout << "Rozmiar: " << Load.size() << "\n";
	int Layer = 0;
	for (auto& coords : Load) {
		vertex[Layer].setPrimitiveType(sf::Quads);
		vertex[Layer].resize(15 * 10 * 4);
		for (int x = 0; x < 15; x++) {
			for (int y = 0; y < 10; y++) {
				sf::Vertex* quad = &vertex[Layer][(x + y * 15) * 4];
				int  tile = coords.second[x + y * 15];
				//std::cout <<"Nr kafla: "<< tile << "\n";
				CollisionMap(x, y, tile, Layer);
				int texX = ((tile-1) % 9);
				int texY = ((tile-1) / 9);
				if (tile > 0) {
					quad[0].position = sf::Vector2f(x * 50, y * 50);
					quad[1].position = sf::Vector2f((x + 1) * 50, y * 50);
					quad[2].position = sf::Vector2f((x + 1) * 50, (y + 1) * 50);
					quad[3].position = sf::Vector2f(x * 50, (y + 1) * 50);
					//std::cout << "Typ kafelka: " << tile << "\n";
					quad[0].texCoords = sf::Vector2f(texX * 50, texY * 50);
					quad[1].texCoords = sf::Vector2f((texX + 1) * 50, texY * 50);
					quad[2].texCoords = sf::Vector2f((texX + 1) * 50, (texY + 1) * 50);
					quad[3].texCoords = sf::Vector2f(texX * 50, (texY + 1) * 50);
				}
			}
		}
		Layer++;
	}
}

void Map::CollisionMap(int x, int y, int tile, int Layer) {
	TileProp tileprop;
	if (Layer == 0) {
		switch (tile) {
		case Map::EMPTY:
			//std::cout <<tile<< " PUSTY: ";
			tileprop.collision = false;
			tileprop.interaction = false;
			break;
		case Map::STONE:
			//std::cout <<tile<< " KAMIEN: ";
			tileprop.collision = true;
			tileprop.interaction = false;
			break;
		case Map::GRASS:
			//std::cout <<tile<< " TRAWA: ";
			tileprop.collision = false;
			tileprop.interaction = true;
			break;
		case Map::MUSHROOM:
			//std::cout <<tile<< " GRZYB: ";
			tileprop.collision = true;
			tileprop.interaction = false;
			break;
		default:
			//std::cout << "NIC";
			tileprop.collision = false;
			tileprop.interaction = false;
			break;
		}
		//std::cout << "x=" << x << "y=" << y << "\n";
		PropMap[x][y] = tileprop;
	}
}


void Map::drawMap() {
	//std::cout << "Rozmiar: " << PropMap.size() << "\n";
	//std::cout << PropMap[0][0].collision;
	//for (auto& i : PropMap)
	//	std::cout << i.collision << "" << i.interaction<< "\n";
 }
void Map::draw() {
	for (auto& p: vertex)
		okno.draw(p, &_Texture);
}

bool Map::collision(int x, int y) {
	//std::cout << "x= " << x << " y= " << y << "\n";
	if (PropMap[x][y].collision)
		return true;
	else
		return false;
}	

bool Map::Interaction(int x, int y) {
	if (PropMap[x][y].interaction)
		return true;
	else
		return false;
}

void Map::LoadMap() {
	std::vector<int> Load = {
		2,2,2,46,47,48,17,17,17,2,2,0,0,17,17,
		2,2,2,61,62,63,46,47,48,0,0,0,0,0,0,
		2,2,2,76,77,78,61,62,63,0,0,0,0,0,0,
		2,2,2,0,0,0,76,77,78,0,0,0,0,0,0,
		2,2,2,46,47,48,0,0,46,47,48,0,0,0,0,
		2,2,2,61,62,63,0,0,61,62,63,0,0,0,0,
		2,2,2,76,77,78,0,0,76,77,78,46,47,48,0,
		2,2,2,0,0,0,0,0,0,0,0,61,62,63,0,
		2,2,2,0,0,0,0,0,0,0,0,76,77,78,0,
		2,2,2,0,0,0,0,0,0,0,0,0,0,0,0 };
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
		//std::make_pair("Layer2", Load2)
	};
	LoadTile(LoadV);
}
