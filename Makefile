# Samuel Jacquet - 06-09-2021

ifeq ($(OS),Windows_NT)
# gcc src/*.c -o bin/prog -I include -Wall -Wextra -Werror -std=c11 -pedantic-errors -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
CC = gcc
EXEC = bin/prog.exe
SRC = $(wildcard src/*.c)
OBJ = $(SRC: .c=.o)
CFLAGS = -I include -Wall -Werror -std=c11 -pedantic-errors #-Wextra
LIBS = -L lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXEC) $(OBJ) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -o $(OBJ) -c $(SRC)

debug:
	gdb -q $(EXEC)

else

gcc src/*.c -o prog $(SDL2-config --cflags --libs) -lSDL2_image -lSDL2_ttf

endif