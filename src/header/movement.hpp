#pragma once
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
	void move_update(int X_size, int Y_size);
	
	virtual void moving() = 0; 

protected:
	int X;
	int Y;
	int dx;
	int dy;
};

