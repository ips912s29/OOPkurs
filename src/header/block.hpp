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
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	int X, Y;
public:
	Block(int X_pos, int Y_pos);
};