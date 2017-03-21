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
public:
	Map(const std::string& TextureFile, sf::Vector2f);
	 ~Map();
	 void draw(sf::RenderWindow& okno);
	 void LoadTile(const std::map<std::string, const std::vector<std::vector<int>>>& Load);
	 bool collision(Character&);
};

