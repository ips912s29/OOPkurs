#include "header/paddle.hpp"

    Paddle::Paddle(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		paddle_sprite.setPosition(X, Y);
		paddle_texture.loadFromFile("images/paddle1.png"); 
		paddle_sprite.setTexture(paddle_texture);
	}
	void Paddle::paddle_move() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& (X < 535)) {
			X += dx;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& (X > 0)) {
			X += -dx;
		}
		paddle_sprite.setPosition(X, Y);
	}

	sf::Sprite Paddle::get_sprite()
	{
		return paddle_sprite;
	}