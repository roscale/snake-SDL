OBJS = Window.cpp Game.cpp Grid.cpp Snake.cpp Food.cpp Timer.cpp Point2D.cpp main.cpp

CC = g++
COMPILER_FLAGS = -w  -std=c++17
LINKER_FLAGS = -lSDL2

OBJ_NAME = game.o

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
