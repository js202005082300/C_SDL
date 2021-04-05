# Samuel Jacquet
# 05-04-2021


# Windows
# gcc src/*.c -o bin/prog -I include -Wall -Wextra -Werror -std=c11 -pedantic-errors -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# bin\prog.exe ou ./bin/prog.exe (PS)

CC = gcc
EXEC = bin/prog.exe
SRC = $(wildcard src/*.c)
OBJ = $(SRC: .c=.o)
CFLAGS = -I include -Wall -Wextra -Werror -std=c11 -pedantic-errors
LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $(OBJ) -c $(SRC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) 
#$(LDFLAGS)

#clean:
#	del /q /f test.txt



# GNU/Linux et MacOS
# gcc src/*.c -o bin/prog $(SDL2-config --cflags --libs)