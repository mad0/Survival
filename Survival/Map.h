#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>

class Map{
private:
	std::string TextureFile;
	sf::Texture _Texture;
	sf::Vector2f Wsize;
	sf::VertexArray vertex[2];
	sf::RenderWindow& okno;
	enum TileType {
		EMPTY,
		STONE=39,
		GRASS=51,
		MUSHROOM
	};
	struct TileProp {
		bool collision;
		bool interaction;
	};
	void CollisionMap(int x, int y, int tile, int);
	
	std::vector<std::vector<TileProp>> PropMap;
	
public:
	Map(sf::RenderWindow&, const std::string& TextureFile, sf::Vector2f);
	 ~Map();
	 void LoadMap();
	 void drawMap();
	 void draw();
	 void LoadTile(const std::map<std::string, const std::vector<int>>& Load);
	 bool collision(int x, int y);
	 bool Interaction(int x, int y);
};

