#pragma once
#include "movement.hpp"

class Paddle: public sf::Sprite
{
private:
	int X, Y;
	int dx = 5;
	sf::Texture paddle_texture;
	sf::Sprite paddle_sprite;
public:
	Paddle(int X_pos, int Y_pos);
	
    void paddle_move();

	sf::Sprite get_sprite();
};