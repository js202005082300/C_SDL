# Samuel Jacquet
# 05-04-2021


# Windows
# gcc src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

CC = gcc
EXE = bin/prog.exe
SRC = $(wildcard src/*.c)
OBJ = $(SRC: .c=.o)
CFLAGS = -I include -std=c99 -Wall -Wextra -pedantic
LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
DEBUGFLAG = -g

all : $(EXE)
.PHONY: clean

%.o : %.c
	$(CC) -o $(OBJ) -c $(SRC) $(LDFLAGS)

$(EXE) : $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(CFLAGS)

clean:
	-del test.txt



# GNU/Linux et MacOS
# gcc src/*.c -o bin/prog $(SDL2-config --cflags --libs)