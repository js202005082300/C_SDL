# Samuel Jacquet
# 25-12-20

CC = gcc
EXEC = prog
SRC = $(wildcard *.c)
OBJ = $(SRC: .c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)
	
%.o : %.c
	$(CC) -o $(OBJ) -c $(SRC)

clean :
	-del *.o
	-del prog.exe

zip :
	7z a -tzip MyGame.zip makefile *.c *.h