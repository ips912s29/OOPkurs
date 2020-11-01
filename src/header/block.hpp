#pragma once
#include "movement.hpp"

class Block: public sf::RectangleShape
{
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	int X, Y;
public:
	Block(int X_pos, int Y_pos);
};