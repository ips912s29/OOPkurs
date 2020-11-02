#include "header/ball.hpp"
	Ball::Ball() {
		radius = 7.f;
		X = 295;
		Y = 300;
		dx = 4;
		dy = 4;
		setRadius(radius);
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
	}

	Ball::Ball(float rad, int X_pos, int Y_pos){
		X = X_pos;
		Y = Y_pos;
		dx = 2;
		dy = 2;
		radius = rad;
		setRadius(rad);
		setPosition(X_pos, Y_pos);
		setFillColor(sf::Color(r,g,b));
	}

	void Ball::moving(Paddle* paddle, Block* block[100])  { 
		move_update(radius*2, radius*2,paddle, block);
		setPosition(X, Y);
	}

	void Ball::dy_reflect() {
		dy *= -1;
	}

	void Ball::dx_reflect() {
		dx *= -1;
	}

	int Ball::get_X() {
		return getPosition().x;;
	}

	int Ball::get_Y() {
		return getPosition().y;
	}


