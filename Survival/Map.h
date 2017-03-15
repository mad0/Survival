#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <memory>

class Map{
private:
	std::string LevelFile;
	std::string TextureFile;
	sf::Texture _Texture;
	sf::Sprite Tile;
	std::vector<std::unique_ptr<sf::Sprite>> TileMap;

public:
	Map(const std::string& TextureFile);
	 ~Map();
	 void draw(sf::RenderWindow& okno);
	 void LoadTile();
};

