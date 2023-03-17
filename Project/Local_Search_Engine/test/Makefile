CC = gcc
#used standard c99 where the __func__ is available to print function names
CFLAGS = -Wall -c -g -std=c99 
OFLAGS = -o
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
BIN = bin/
INCLUDE = -I../include/ -I./
HEADER = ../include/
SRC = ../src/
OBJ = obj/
CUNIT_LIB_DIR = -L/usr/lib/    #location of CUnit library
CUNIT_INC_DIR = /usr/include/CUnit/
AUT_INC =  -I$(CUNIT_INC_DIR)

#using shared library
all: test

test: test.o testfunction.o 
	$(CC) $(OFLAGS) test test.o testfunction.o $(CUNIT_LIB_DIR) -lcunit
test.o: test.c testfunction.h 
	$(CC) $(CFLAGS) test.c ${AUT_INC}

testfunction.o: testfunction.c ../inc/function.h  
	$(CC) $(CFLAGS) testfunction.c $(INCLUDE) ${AUT_INC}

function_definition.o: ../src/function_definition.c ../inc/function.h  
	$(CC) $(CFLAGS) ../src/function_definition.c -I../include/ -I./

clean: 
	rm -f test
	rm -f *.o

