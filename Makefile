OBJS = sdl_helper.cpp Game.cpp Grid.cpp Point2D.cpp Snake.cpp Food.cpp main.cpp

CC = g++
COMPILER_FLAGS = -w  -std=c++11
LINKER_FLAGS = -lSDL2

OBJ_NAME = game.o

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
