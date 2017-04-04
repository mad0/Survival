#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <memory>
#include "Character.h"
#include <vector>

class Map{
private:
	std::string TextureFile;
	sf::Texture _Texture;
	sf::Vector2f Wsize;
	std::vector<std::unique_ptr<sf::Sprite>> TileMap;
	sf::VertexArray vertex[2];
	sf::RenderWindow& okno;
	enum TileType {
		EMPTY,
		STONE,
		GRASS,
		MUSHROOM
	};
	struct TileProp {
		bool collision;
		bool interaction;
	};
	void CollisionMap(int tile);
	std::map<int, TileProp> PropMap;
public:
	Map(sf::RenderWindow&, const std::string& TextureFile, sf::Vector2f);
	 ~Map();
	 void draw();
	 void LoadTile(const std::map<std::string, const std::vector<int>>& Load);
	 bool collision(Character&);
};

