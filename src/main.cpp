#include "header/movement.hpp"
#include "header/block.hpp"
#include "header/paddle.hpp"
#include "header/ball.hpp"

class class_window{
public:			 
	class_window(){
        window.create(sf::VideoMode(630, 600), "Arcanoid");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);   
    };

	~class_window(){
		window.close();
	};

	void start(){
		srand(time(0));
		Ball* ball = new Ball;
		Block* block[70];
		Paddle* paddle = new Paddle(315,590);
		int block_number = 0;
		for(int i = 0; i < 14; ++i) {
			block[block_number] = new Gray_Block(i*45, 5*21);
			block_number++;
		}
		for(int i = 0; i < 14; ++i) {
			for(int j = 1; j < 5; ++j) {
				block[block_number] = new Block(i*45,j*21);
				block_number++;	
			}
		}
		while(window.isOpen()){
			sf::Event event;
        	while (window.pollEvent(event)) {
        		if(event.type == sf::Event::Closed)
					window.close();
			}
            window.clear();
			start(ball, paddle, block);
			for (int i = 0; i < 70; i++) block_draw(block[i]);
		    window.display();
    	}
    	delete ball;
		for(int i = 0; i < 70; ++i) delete(block[i]);
	};

private:

    void start(Ball* ball, Paddle* paddle, Block* block[70]){
    	ball->moving(paddle, block);
        window.draw(*ball);
		paddle->paddle_move();
		window.draw(paddle->get_sprite());
    }

	void block_draw(Block* block){
        window.draw(*block);
    }

    sf::RenderWindow window; //экземпляр окна
};

int main()
{
	class_window scene;
	scene.start(); //запуск
	return 0;
}
