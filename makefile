FLAGS += -Wall -Werror --std=c++17 
USER_DIR_S = build/src
EXECUTABLE = bin/program

.PHONY: all clean start addDir

LDFLAGS += -Wall -Wextra -pthread --std=c++17

all: $(EXECUTABLE)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/block.o $(USER_DIR_S)/paddle.o $(USER_DIR_S)/ball.o $(USER_DIR_S)/movement.o
	g++ $(FLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c $^ -o $@

$(USER_DIR_S)/block.o: src/block.cpp
	g++ $(FLAGS) -c $^ -o $@

$(USER_DIR_S)/paddle.o: src/paddle.cpp
	g++ $(FLAGS) -c $^ -o $@

$(USER_DIR_S)/ball.o: src/ball.cpp
	g++ $(FLAGS) -c $^ -o $@

$(USER_DIR_S)/movement.o: src/movement.cpp
	g++ $(FLAGS) -c $^ -o $@

start:
	./bin/program

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf bin/*
