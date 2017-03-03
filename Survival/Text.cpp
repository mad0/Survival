#include "Text.h"
#include <iostream>

Text::Text(const std::string& data, const std::string& czcionka) : data(data), czcionka(czcionka) {
	std::cout << "Tworze obiekt klasy Tekst...\n";
	font.loadFromFile(czcionka);
	txt.setFont(font);
	txt.setString(data);
	txt.setPosition(poz);
	txt.setFillColor(sf::Color(195, 195, 195, 255));
	txt.setCharacterSize(50);
	fade = 10;
};

void Text::draw(sf::RenderWindow &okno) {
	okno.draw(txt);
};

void Text::FadeOut() {
	std::cout << fade << "\n";
	txt.setFillColor(sf::Color(195, 195, 195, fade));
	if (fade<255)
		fade++;
};

sf::FloatRect Text::GetSize() {
	return txt.getGlobalBounds();
}

void Text::setPosition(float x, float y) {
	txt.setPosition(x, y);
}

void Text::setSize(float size) {
	txt.setCharacterSize(size);
}

void Text::setColor(sf::Color color) {
	txt.setFillColor(color);
}

Text::~Text() {
	std::cout << "Usuwam obiekt klasy Tekst...\n";
};