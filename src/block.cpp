#include "header/block.hpp"

    Block::Block(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
	}

	bool Block::get_breakable() {
		return breakable;
	}

	void Block::set_breakable(bool x) {
		breakable = x;
	}