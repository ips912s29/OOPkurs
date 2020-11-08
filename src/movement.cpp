#include "header/movement.hpp"

	void class_movement::move_update(int X_size, int Y_size, Paddle* paddle, Block* block[70]) {
        //int block_x = 0, block_y = 0;
        bool flag = 0;
		Y += dy;
        if(Y < 0) dy = -dy;
        if(!flag) {
            for (int i = 0; i < 70; i++)
                if (sf::FloatRect(X, Y, 1, 1).intersects(block[i]->getGlobalBounds())) {
                    if(block[i]->get_breakable()) {
                        block[i]->setPosition(-70, 0);                    
                        dy = -dy;
                    } else {
                        dy = -dy;
                    }
                    flag = 1;                
                }
        } 
        X += dx;
        if(X > (629 - (int)X_size) || X < 0) dx = -dx;
        if(!flag) {
            for(int i = 0; i < 70; i++)
                if (sf::FloatRect(X, Y, 1, 1).intersects(block[i]->getGlobalBounds())) {
                    if(block[i]->get_breakable()) {
                        block[i]->setPosition(-70, 0);                    
                        dx = -dx;
                    } else {
                        dx = -dx;
                    }
                    flag = 1;                
                }
        }        
     
		if (sf::FloatRect(X, Y, 10, 10).intersects(paddle->get_sprite().getGlobalBounds())) {
            dy = -(rand()%4 + 2);
            dy += rand()%2;
        }
	}
