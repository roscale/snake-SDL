OBJS = sdl_helper.cpp Grid.cpp Point2D.cpp Snake.cpp Food.cpp main.cpp

CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2

OBJ_NAME = game.o

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
