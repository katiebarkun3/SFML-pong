#pragma once
#include "SFML/Graphics.hpp"
class Ball {
private:
	sf::CircleShape circle;
	sf::FloatRect hitbox;
	float radius = 20.f;
	float speedx = 5.f;
	float speedy = -5.f;
	size_t left_score = 0;
	size_t right_score = 0;
	sf::Vector2f midtop;
	sf::Vector2f midleft;
	sf::Vector2f midbottom;
	sf::Vector2f midright;
public: 
	Ball();
	sf::CircleShape getShape();
	sf::Vector2f getPosition();
	void update();
	sf::FloatRect getHitBox();
	void reboundHorizontal();
	void reboundVertical();
	size_t getLeftScore();
	size_t getRightScore();
	sf::Vector2f getMidtop();
	sf::Vector2f getMidleft();
	sf::Vector2f getMidbottom();
	sf::Vector2f getMidright();
	float getRadius();
	void setPosition(sf::Vector2f);
};