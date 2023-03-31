CC = gcc
CFLAGS = -Wall -c -g
LDFLAGS = -o

BIN = ./bin/
SRC = ./src/
OBJ = ./obj/
INC = ./inc/

IFLAGS = -I $(INC)

all: project

project:$(OBJ)/main.o
	$(CC) $(LDFLAGS) $(BIN)/rse $(OBJ)/main.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv *.o $(OBJ)/


clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
	


