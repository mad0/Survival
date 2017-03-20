#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Character.h"
#include <vector>

class Map{
private:
	std::string LevelFile;
	std::string TextureFile;
	sf::Texture _Texture;
	sf::Sprite Tile;
	sf::Vector2f Wsize;
	std::vector<std::unique_ptr<sf::Sprite>> TileMap;
	int loadX;
	int loadY;
	sf::VertexArray wierzcholki;
public:
	Map(const std::string& TextureFile, sf::Vector2f);
	 ~Map();
	 void draw(sf::RenderWindow& okno);
	 void LoadTile(const std::vector<std::vector<int>>& Load, int loadX, int loadY);
	 bool collision(Character&);
};

