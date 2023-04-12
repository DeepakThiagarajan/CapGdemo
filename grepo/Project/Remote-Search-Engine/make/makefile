CC=gcc
CFLAGS= -Wall -c -g
LDFLAGS=-o

SRC=./src
OBJ=./obj
BIN=./bin
INC=./include/

IFLAGS = -I $(INC)

all : server client

server : $(OBJ)/server.o $(OBJ)/server_functions.o 
	$(CC) $(LDFLAGS) $(BIN)/server $(OBJ)/server.o $(OBJ)/server_functions.o
	

$(OBJ)/server.o : $(SRC)/server.c 
	$(CC) $(CFLAGS) $(SRC)/server.c $(IFLAGS)
	mv *.o $(OBJ)/

$(OBJ)/server_functions.o : $(SRC)/server_functions.c 
	$(CC) $(CFLAGS) $(SRC)/server_functions.c $(IFLAGS)
	mv *.o $(OBJ)/

client : $(OBJ)/client.o $(OBJ)/client_functions.o
	$(CC)  $(LDFLAGS) $(BIN)/client $(OBJ)/client.o $(OBJ)/client_functions.o


$(OBJ)/client.o : $(SRC)/client.c
	$(CC) $(CFLAGS)  $(SRC)/client.c $(IFLAGS)
	mv *.o $(OBJ)/
	
$(OBJ)/client_functions.o : $(SRC)/client_functions.c
	$(CC) $(CFLAGS) $(SRC)/client_functions.c $(IFLAGS)
	mv *.o $(OBJ)/

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
	@echo "CLEANING DONE!!" 
