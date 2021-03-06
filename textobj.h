#pragma once
#include "SFML/Graphics.hpp"

class TextObj {
private:
	sf::Font font;
	sf::Text text;
public:
	TextObj(float x, float y) {
		font.loadFromFile("ds-digib.ttf");
		text.setFont(font);
		text.setFillColor(sf::Color(204, 153, 255));
		text.setCharacterSize(72);
		text.setPosition(x, y);
	}
	void update(std::string str) { text.setString(str); }
	sf::Text getText() { return text; }
};