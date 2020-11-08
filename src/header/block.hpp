#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

class Block: public sf::RectangleShape
{
protected:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	int X, Y;
	bool breakable;
public:
	Block();
	Block(int X_pos, int Y_pos);
	bool get_breakable();
	void set_breakable(bool x);
	int get_X();
	int get_Y();
};

class Gray_Block: public Block
{
public:
	Gray_Block(int X_pos, int Y_pos);
};