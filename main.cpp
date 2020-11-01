#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>


class class_movement{
public:
	void move_update(int X_size, int Y_size){
		if(X > (600 - (int)X_size) || X < 0){ 
			dx = -dx;					
		}
		if(/*Y > (600 - (int)Y_size) ||*/Y < 0){
			dy = -dy;
		}

		X += dx;
		Y += dy;
	}
	
	virtual void moving() = 0; 

protected:
	int X;
	int Y;
	int dx;
	int dy;
};

class Ball: public sf::CircleShape, public class_movement{
public:
	Ball(){
		radius = 7.f;
		X = 300;
		Y = 300;
		dx = 4;
		dy = 4;
		setRadius(radius);
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
	}

	Ball(float rad, int X_pos, int Y_pos){
		X = X_pos;
		Y = Y_pos;
		dx = 2;
		dy = 2;
		radius = rad;
		setRadius(rad);
		setPosition(X_pos, Y_pos);
		setFillColor(sf::Color(r,g,b));
	}

	void moving() override { 
		move_update(radius*2, radius*2);
		setPosition(X, Y);
	}

	void dy_reflect() {
		dy *= -1;
	}

	void dx_reflect() {
		dx *= -1;
	}

	int get_X() {
		return getPosition().x;;
	}

	int get_Y() {
		return getPosition().y;
	}
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	float radius;
};

class Block: public sf::RectangleShape
{
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	int X, Y;
public:
	Block(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
	}
};

class Paddle: public sf::Sprite
{
private:
	int X, Y;
	int dx = 5;
	sf::Texture paddle_texture;
	sf::Sprite paddle_sprite;
public:
	Paddle(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		paddle_sprite.setPosition(X, Y);
		paddle_texture.loadFromFile("images/paddle1.png"); 
		paddle_sprite.setTexture(paddle_texture);
	}
	void paddle_move() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& (X < 535)) {
			X += dx;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& (X > 0)) {
			X += -dx;
		}
		paddle_sprite.setPosition(X, Y);
	}

	sf::Sprite get_sprite()
	{
		return paddle_sprite;
	}
};

class class_window{
public:			 
	class_window(){
        window.create(sf::VideoMode(630, 600), "Arcanoid");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);   
    };

	~class_window(){
		window.close();
	};

	void start(){
		srand(time(0));
		Ball* ball = new Ball;
		Block* block[100];
		Paddle* paddle = new Paddle(315,590);
		int block_number = 0;
		for(int i = 0; i < 20; ++i) {
			for(int j = 1; j <= 5; ++j) {
				block[block_number] = new Block(i*45,j*21);
				block_number++;	
			}
		}
		while(window.isOpen()){
			sf::Event event;
        	while (window.pollEvent(event)) {
        		if(event.type == sf::Event::Closed)
					window.close();
			}
            window.clear();
			motions_draw(ball, paddle);
			if (sf::FloatRect(ball->get_X(), ball->get_Y(), 10, 10).intersects(paddle->get_sprite().getGlobalBounds())) ball->dy_reflect();
			for (int i = 0; i < 100; i++)
				if (sf::FloatRect(ball->get_X(), ball->get_Y(), 10, 10).intersects(block[i]->getGlobalBounds()))
				{
					block[i]->setPosition(-100, 0);
					ball->dy_reflect();
				}
			for(int i = 0; i < 100; ++i) block_draw(block[i]);
		    window.display();
    	}
    	delete ball;
		for(int i = 0; i < 100; ++i) delete(block[i]);
	};

private:

    void motions_draw(Ball* ball, Paddle* paddle){
    	ball->moving();
        window.draw(*ball);
		paddle->paddle_move();
		window.draw(paddle->get_sprite());
    }

	void block_draw(Block* block){
        window.draw(*block);
    }

    sf::RenderWindow window; //экземпляр окна
};

int main()
{
	class_window scene;
	scene.start(); //запуск
	return 0;
}
