#include "ball.h"
#include "const.h"

Ball::Ball() {
	circle.setRadius(radius);
	circle.setPosition(WINDOW_WIDTH / 2 - radius, WINDOW_HEIGHT / 2 - radius);
	circle.setFillColor(sf::Color(100, 220, 0));

}
sf::CircleShape Ball::getShape() { return circle; }
float Ball::getSpeedx() { return speedx; }
float Ball::getSpeedy() { return speedy; }
sf::Vector2f Ball::getPosition() { return circle.getPosition(); }
void Ball::update() {
	circle.move(speedx, speedy);
	if (getPosition().x <= 0 || getPosition().x + 2 * radius >= WINDOW_WIDTH) {
		speedx = -speedx;
	}
	if (getPosition().y <= 0 || getPosition().y + 2 * radius >= WINDOW_HEIGHT) {
		speedy = -speedy;
	}
}