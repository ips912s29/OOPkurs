#include "header/movement.hpp"

	void class_movement::move_update(int X_size, int Y_size){
		if(X > (600 - (int)X_size) || X < 0){ 
			dx = -dx;					
		}
		if(Y < 0){
			dy = -dy;
		}

		X += dx;
		Y += dy;
	}


