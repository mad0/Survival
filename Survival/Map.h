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
	sf::Vector2f Wsize;
	std::vector<std::unique_ptr<sf::Sprite>> TileMap;

public:
	Map(const std::string& TextureFile, sf::Vector2f);
	 ~Map();
	 void draw(sf::RenderWindow& okno);
	 void LoadTile();
};

