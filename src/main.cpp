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
		Ball* circle = new Ball;
		Block* block1[100];
		Paddle* paddle1 = new Paddle(315,590);
		int block_number = 0;
		for(int i = 0; i < 20; ++i) {
			for(int j = 1; j <= 5; ++j) {
				block1[block_number] = new Block(i*45,j*21);
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
			motions_draw(circle, paddle1);
			if (sf::FloatRect(circle->get_X(), circle->get_Y(), 10, 10).intersects(paddle1->get_sprite().getGlobalBounds())) circle->dy_reflect();
			for (int i = 0; i < 100; i++)
				if (sf::FloatRect(circle->get_X(), circle->get_Y(), 10, 10).intersects(block1[i]->getGlobalBounds()))
				{
					block1[i]->setPosition(-100, 0);
					circle->dy_reflect();
				}
			for(int i = 0; i < 100; ++i) block_draw(block1[i]);
		    window.display();
    	}
    	delete circle;
		for(int i = 0; i < 100; ++i) delete(block1[i]);
	};

private:

    void motions_draw(Ball* circle, Paddle* paddle1){
    	circle->moving();
        window.draw(*circle);
		paddle1->paddle_move();
		window.draw(paddle1->get_sprite());
    }

	void block_draw(Block* block1){
        window.draw(*block1);
    }

    sf::RenderWindow window; //экземпляр окна
};

int main()
{
	class_window scene;
	scene.start(); //запуск
	return 0;
}
