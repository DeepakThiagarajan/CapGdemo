CC = gcc
CFLAGS = -Wall -c -g -std=c99 
OFLAGS = -o
BIN = ./bin/
SRC = ./src/
OBJ = ./obj/
INC = -I
HEAD = ./inc/

all:$(BIN)RSE

$(OBJ)main.o:$(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c $(INC) $(HEAD) $(OFLAGS) $(OBJ)main.o

$(BIN)RSE:$(OBJ)main.o
	$(CC) $(OFLAGS) $(BIN)RSE $(OBJ)main.o

clean: 
	rm $(OBJ)*.o $(BIN)*
