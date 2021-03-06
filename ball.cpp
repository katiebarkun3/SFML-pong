#include "ball.h"
#include "const.h"
Ball::Ball() {
	circle.setRadius(radius);
	circle.setPosition(WINDOW_WIDTH / 2 - radius, WINDOW_HEIGHT / 2 - radius);
	circle.setFillColor(sf::Color(206, 153, 255));

}
sf::CircleShape Ball::getShape() { return circle; }
void Ball::reboundHorizontal() { speedx = -speedx; }
void Ball::reboundVertical() { speedy = -speedy; }
sf::Vector2f Ball::getPosition() { return circle.getPosition(); }
sf::FloatRect Ball::getHitBox() { return circle.getGlobalBounds(); }
size_t Ball::getLeftScore() { return left_score; }
size_t Ball::getRightScore() { return right_score; }
sf::Vector2f Ball::getMidtop() { return midtop; }
sf::Vector2f Ball::getMidleft() { return midleft; }
sf::Vector2f Ball::getMidbottom() { return midbottom; }
sf::Vector2f Ball::getMidright() { return midright; }
void Ball::setPosition(sf::Vector2f position) { circle.setPosition(position); }
float Ball::getRadius() { return radius; }
void Ball::update() {
	//вычисляем середины сторон
	midtop = sf::Vector2f(circle.getPosition().x + radius, circle.getPosition().y);
	midleft = sf::Vector2f(circle.getPosition().x, circle.getPosition().y + radius);
	midbottom = sf::Vector2f(circle.getPosition().x + radius, circle.getPosition().y + 2*radius);
	midright = sf::Vector2f(circle.getPosition().x + 2 * radius, circle.getPosition().y + radius);
	//движение мяча
	circle.move(speedx, speedy);
	//если мяч ударяется о границы экрана
	if (getPosition().x <= 0) {
		speedx = -speedx;
		right_score++;
	}
	if (getPosition().x + 2 * radius >= WINDOW_WIDTH) {
		speedx = -speedx;
		left_score++;
	}
	if (getPosition().y <= 0) {
		speedy = -speedy;
	}
	if (getPosition().y + 2 * radius >= WINDOW_HEIGHT) {
		speedy = -speedy;
	}
}