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
		if(Y > (600 - (int)Y_size) || Y < 0){
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

class ball: public sf::CircleShape, public class_movement{
public:
	ball(){
		radius = 7.f;
		X = 300;
		Y = 300;
		dx = 2;
		dy = 2;
		setRadius(radius);
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
	}

	ball(float rad, int X_pos, int Y_pos){
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

private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	float radius;
};

class block: public sf::RectangleShape
{
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	int X, Y;
public:
	block(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
	}
};

class paddle: public sf::RectangleShape
{
private:
	int X, Y;
	int dx = 5;
public:
	paddle(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setSize(sf::Vector2f(50.f, 10.f));
		setFillColor(sf::Color(100,100,100));
	}
	void paddle_move() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& (X < 580)) {
			X += dx;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& (X > 0)) {
			X += -dx;
		}
		setPosition(X, Y);
	}
};
class intersections:public paddle, public ball
{

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
		ball* circle = new ball;
		block* block1[100];
		paddle* paddle1 = new paddle(315,590);
		int block_number = 0;
		for(int i = 0; i < 20; ++i) {
			for(int j = 1; j <= 5; ++j) {
				block1[block_number] = new block(i*45,j*21);
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
			motions_draw(circle, paddle1);
			
			for(int i = 0; i < 100; ++i) block_draw(block1[i]);
		    window.display();
    	}
    	delete circle;
		for(int i = 0; i < 100; ++i) delete(block1[i]);
	};

private:

    void motions_draw(ball* circle, paddle* paddle1){
    	circle->moving();
        window.draw(*circle);
		paddle1->paddle_move();
		window.draw(*paddle1);
    }

	void block_draw(block* block1){
        window.draw(*block1);
    }

    sf::RenderWindow window; //экземпляр окна
};

int main()
{
	class_window scene;
	scene.start(); //запуск
	return 0;
}
