#include "Map.h"
#include <iostream>
#include <SFML\Graphics.hpp>


Map::Map(sf::RenderWindow& okno, const std::string& TextureFile, sf::Vector2f Wsize) : okno(okno), TextureFile(TextureFile), Wsize(Wsize){
	_Texture.loadFromFile(TextureFile);
	std::cout << "Tworze kafelek...\n";
	PropMap.assign(40, std::vector<TileProp>(19));
}

Map::~Map(){
	std::cout << "Niszcze kafelek...\n";
}

void Map::LoadTile(const std::map<std::string, const std::vector<int>>& Load) {
	std::cout << "Rozmiar: " << Load.size() << "\n";
	int Layer = 0;
	for (auto& coords : Load) {
		vertex[Layer].setPrimitiveType(sf::Quads);
		vertex[Layer].resize(40 * 19 * 4);
		for (int x = 0; x < 40; x++) {
			for (int y = 0; y < 19; y++) {
				sf::Vertex* quad = &vertex[Layer][(x + y * 40) * 4];
				
				//std::cout << "x=" << x << "y=" << y << " suma=" << x + y * 10 << "\n";
				int  tile = coords.second[x + y * 40];
				//std::cout <<"Nr kafla: "<< tile << "\n";
				CollisionMap(x, y, tile);
				int texX = ((tile-1) % 9);
				int texY = ((tile-1) / 9);
				if (tile > 0) {
					quad[0].position = sf::Vector2f(x * 32, y * 32);
					quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
					quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
					quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);
					std::cout << "Typ kafelka: " << tile << "\n";
					quad[0].texCoords = sf::Vector2f(texX * 32, texY * 32);
					quad[1].texCoords = sf::Vector2f((texX + 1) * 32, texY * 32);
					quad[2].texCoords = sf::Vector2f((texX + 1) * 32, (texY + 1) * 32);
					quad[3].texCoords = sf::Vector2f(texX * 32, (texY + 1) * 32);
				}
			}
		}
		Layer++;
	}
}

void Map::CollisionMap(int x, int y, int tile) {
	TileProp tileprop;
	switch (TileType(tile)) {
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
			tileprop.interaction = false;
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
	std::cout << "x=" << x << "y=" <<y<< "\n";
	PropMap[x][y]=tileprop;
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
	//std::cout << x << " " << y << "\n";
	//sf::Vector2f curPos = player.getPosition();
	//std::cout << player.getPosition().x << " " << player.getPosition().y << "\n";
	//if (TileMap[11]->getGlobalBounds().intersects(player.getBounds()))
	//	return true;
	
	//if (TileMap[1]->getGlobalBounds().intersects(player.getPosition()))
	//	std::cout << "KAFEL11111111111\n";
