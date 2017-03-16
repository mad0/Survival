#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class Character {
private:
	int hp;
	std::string Iname;
	sf::Sprite Char;
	sf::Texture CharTexture;
	//std::vector <std::unique_ptr<Items>> bag;
	//Items jeden;
	sf::RenderWindow& okno;
	sf::View gra;
public:
	Character(int hp, sf::RenderWindow& okno);
	~Character();
	int show_hp();
	int bagSize();
	void move(float, float);
	void draw();

};

