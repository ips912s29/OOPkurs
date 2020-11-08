#include "header/movement.hpp"

	void class_movement::move_update(int X_size, int Y_size, Paddle* paddle, Block* block[70]) {
	
		X += dx;
        if(X > (629 - (int)X_size) || X < 0) dx = -dx;
        for (int i = 0; i < 70; i++)
            if (sf::FloatRect(X, Y, 5, 5).intersects(block[i]->getGlobalBounds())) {
                if(block[i]->get_breakable()) block[i]->setPosition(-70, 0);
                dx = -dx;
            }

		Y += dy;
        if(Y < 0) dy = -dy;
        for (int i = 0; i < 70; i++)
            if (sf::FloatRect(X, Y, 5, 5).intersects(block[i]->getGlobalBounds())) {
                if(block[i]->get_breakable()) block[i]->setPosition(-70, 0);                    
                dy = -dy;
            }

		if (sf::FloatRect(X, Y, 10, 10).intersects(paddle->get_sprite().getGlobalBounds())) {
            dy = -(rand()%4 + 2);
            dy += rand()%2;
        }
	}
