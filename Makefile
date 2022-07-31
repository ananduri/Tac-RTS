OBJS = main.cpp

OBJ_NAME = main

all : $(OBJS)
	g++ $(OBJS) -o $(OBJ_NAME) -w -lSDL2
