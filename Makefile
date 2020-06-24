LIBS=-lSDL2 -lSDL2main
CFLAGS=-std=c++11
CC=g++
EXEEXT=
RM=rm

NAME=main

run: $(NAME)
	./$(NAME)$(EXEEXT)

$(NAME): Game.o GameOfLife.o main.o 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) *.o $(NAME)$(EXEEXT)
