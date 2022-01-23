#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"
#include "bat.h"
#include "left_bat.h"
using namespace sf;
int main() {
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);
	Ball ball;
	LeftBat left_bat(20, WINDOW_HEIGHT / 2 - 50);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		ball.update();
		left_bat.update();
		window.clear(/*Color(226, 236, 87, 200)*/);
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.display();
	}
	return 0;
}