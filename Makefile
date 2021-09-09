# Samuel Jacquet - 09-09-2021

CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC: .c=.o)
CFLAGS = -I include -Wall -Werror -std=c11 -pedantic-errors #-Wextra
DEBUG = -g

ifeq ($(OS),Windows_NT)
	EXEC = bin\prog.exe
	LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
	LIBS = -L lib
else
	EXEC = ./prog
	LDFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_ttf
	LIBS =
endif

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(DEBUG) -o $(EXEC) $(OBJ) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -o $(OBJ) -c $(SRC)

valgrind:
ifneq ($(OS),Windows_NT)
	valgrind --leak-check=yes $(EXEC)
endif

clean:
ifeq ($(OS),Windows_NT)
	-del ${EXEC}
else
	-rm -rf ${EXEC}
endif