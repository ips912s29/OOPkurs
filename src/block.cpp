#include "header/block.hpp"

    Block::Block(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
		breakable = 1;
	}

	Block::Block() {
		X = -70;
		Y = 0;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
		breakable = 1;
	}

	Gray_Block::Gray_Block(int X_pos, int Y_pos) {
		X = X_pos;
		Y = Y_pos;
		setPosition(X, Y);
		setFillColor(sf::Color(r,g,b));
		setSize(sf::Vector2f(44.f, 20.f));
		breakable = 1;
	}

	bool Block::get_breakable() {
		return breakable;
	}

	int Block::get_X() {
		return getPosition().x;;
	}

	int Block::get_Y() {
		return getPosition().y;
	}

	void Block::set_breakable(bool x) {
		breakable = x;
		setFillColor(sf::Color(255, 0, 0));
	}

	