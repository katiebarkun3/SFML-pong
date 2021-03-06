#pragma once
#include "bat.h"
#include "const.h"

class RightBat : public Bat {
public:
	RightBat(float startx, float starty) :Bat(startx, starty) {}
	void update() {
		int currentx = rect.getPosition().x;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			rect.move(0, -speedy);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			rect.move(0, speedy);
		}
		if (rect.getPosition().y <= 0) {
			rect.setPosition(currentx, 0);
		}
		if (rect.getPosition().y + height >= WINDOW_HEIGHT) {
			rect.setPosition(currentx, WINDOW_HEIGHT - height);
		}

	}
};