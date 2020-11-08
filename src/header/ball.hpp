#pragma once
#include "movement.hpp"

class Ball: public sf::CircleShape, public class_movement{
public:
	Ball();

	Ball(float rad, int X_pos, int Y_pos);

	void moving(Paddle* paddle, Block* block[70]) override;

	void dy_reflect();

	void dx_reflect();

	int get_X();

	int get_Y();
private:
	int	r = rand()%255;
	int	g = rand()%255;
	int	b = rand()%255;
	float radius;
};

