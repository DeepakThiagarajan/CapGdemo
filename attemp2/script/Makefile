CC= gcc
CFLAGS= -Wall -c -g
LDFLAGS= -o

INC=./inc/
SRC=./src
BIN=./bin
OBJ=./obj

all: server client
server: $(OBJ)/server.o
	$(CC) $(LDFLAGS) $(BIN)/server $(OBJ)/server.o

$(OBJ)/server.o: $(SRC)/server.c
	$(CC) $(CFLAGS) $(SRC)/server.c
	mv *.o $(OBJ)/

client: $(OBJ)/client.o
	$(CC) $(LDFLAGS) $(BIN)/client $(OBJ)/client.o

$(OBJ)/client.o: $(SRC)/client.c
	$(CC) $(CFLAGS) $(SRC)/client.c
	mv *.o $(OBJ)/

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

	@echo "Cleared !!"
