# Samuel Jacquet - 05-04-2021

CC = gcc
EXEC = bin/prog.exe
SRC = $(wildcard src/*.c)
OBJ = $(SRC: .c=.o)
CFLAGS = -I include -Wall -Wextra -Werror -std=c11 -pedantic-errors
LIBS = -L lib
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $(EXEC) $(OBJ) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -o $(OBJ) -c $(SRC)

#clean:
#	del /q /f test.txt



# gcc src/*.c -o bin/prog -I include -Wall -Wextra -Werror -std=c11 -pedantic-errors -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# gcc src/*.c -o bin/prog $(SDL2-config --cflags --libs)