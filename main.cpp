#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"
#include "bat.h"
#include "left_bat.h"
#include "right_bat.h"
#include "textobj.h"
using namespace sf;
int main()
{
	enum GameState{INTRO, PLAY, GAME_OVER};
	GameState game_state = INTRO;


	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);

	Ball ball;
	LeftBat left_bat(20, WINDOW_HEIGHT / 2 - 50);
	RightBat right_bat(WINDOW_WIDTH - 40, WINDOW_HEIGHT / 2 - 50);
	TextObj left_score(WINDOW_WIDTH * 1/5, 20);
	TextObj right_score(WINDOW_WIDTH * 4/5, 20);
	TextObj intro_text(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					game_state = PLAY;
				}
			}
		}
		switch (game_state) {
		case INTRO:
			intro_text.update("PONG");
			window.clear(Color(26, 0, 51));
			window.draw(intro_text.getText());
			window.display();
			break;
		case PLAY:
			ball.update();
			left_bat.update();
			right_bat.update();
			left_score.update(std::to_string(ball.getLeftScore()));
			right_score.update(std::to_string(ball.getRightScore()));
			//обработка столкновений 
			//если прямоугольник мяча  пересекается с прямоугольником левой биты
			if (ball.getHitBox().intersects(left_bat.getHitBox())) {

				//удар сверху
				if (left_bat.getHitBox().contains(ball.getMidbottom())) {
					ball.setPosition(sf::Vector2f(ball.getPosition().x,
						left_bat.getPosition().y - 2 * ball.getRadius()));
					ball.reboundVertical();
				}

				//удар справа
				else if (left_bat.getHitBox().contains(ball.getMidleft())) {
					ball.setPosition(sf::Vector2f(left_bat.getPosition().x + left_bat.getWidth(),
						ball.getPosition().y));


					ball.reboundHorizontal();
				}

				//удар снизу
				else if (left_bat.getHitBox().contains(ball.getMidtop())) {
					ball.setPosition(sf::Vector2f(ball.getPosition().x,
						left_bat.getPosition().y + left_bat.getHeight()));
					ball.reboundVertical();
				}
			}
			//если прямоугольник мяча  пересекается с прямоугольником правой биты
			if (ball.getHitBox().intersects(right_bat.getHitBox())) {




				ball.reboundHorizontal();
			}
			//отрисовка окна
			window.clear(Color(26, 0, 51));
			window.draw(ball.getShape());
			window.draw(left_bat.getShape());
			window.draw(right_bat.getShape());
			window.draw(left_score.getText());
			window.draw(right_score.getText());
			window.display();
			break;
		case GAME_OVER:

			break;
		}
	}

	return 0;
}