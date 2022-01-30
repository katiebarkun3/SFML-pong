#pragma once
#include "SFML/Graphics.hpp"
class Bat {
protected:
	sf::RectangleShape rect;
	float width = 20.f;
	float height = 100.f;
	float speedy = 7.f;
public:
	Bat(float startx, float starty) {
		rect.setSize(sf::Vector2f(width, height));
		rect.setPosition(startx, starty);
		rect.setFillColor(sf::Color(206, 153, 255));
	}
		sf::RectangleShape getShape() { return rect; }
		sf::FloatRect getHitBox() { return rect.getGlobalBounds(); }
		sf::Vector2f getPosition() { return rect.getPosition(); }
		int getHeight() { return height; }
		int getWidth() { return width; }
};