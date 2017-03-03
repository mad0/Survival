#pragma once
#include <SFML\Graphics.hpp>
#include <string>
class Text {
private:
	sf::Text txt;
	sf::Font font;
	const std::string& czcionka;
	const std::string& data;
	sf::Vector2f poz;
	int fade;
public:
	Text(const std::string &, const std::string&);
	~Text();
	void draw(sf::RenderWindow &okno);
	void FadeOut();
	sf::FloatRect GetSize();
	void setPosition(float, float);
	void setSize(float);
	void setColor(sf::Color);
};
