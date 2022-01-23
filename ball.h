#pragma once
#include "SFML/Graphics.hpp"
class Ball {
private:
	sf::CircleShape circle;
	float radius = 20.f;
	float speedx = 5.f;
	float speedy = -5.f;
public: 
	Ball();
	sf::CircleShape getShape();
	float getSpeedx();
	float getSpeedy();
	sf::Vector2f getPosition();
	void update();

};