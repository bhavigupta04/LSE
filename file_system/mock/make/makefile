SRC=../src
BIN=../bin
OBJ=../obj
INC=../inc

CC=gcc
GLIBFLAGS=`pkg-config --cflags --libs glib-2.0`
CFLAGS= -c -g -Wall
IFLAGS=-I$(INC)

all: $(BIN)/exe

$(BIN)/exe : $(OBJ)/main.o $(OBJ)/util.o
	$(CC) $(GLIBFLAGS) $(OBJ)/main.o $(OBJ)/util.o -o $(BIN)/exe

$(OBJ)/main.o : $(SRC)/main.c $(INC)/util.h
	$(CC) $(CFLAGS) $(IFLAGS) $(GLIBFLAGS) $(SRC)/main.c
	mv *.o $(OBJ)/

$(OBJ)/util.o : $(SRC)/util.c 
	$(CC) $(CFLAGS) $(IFLAGS) $(GLIBFLAGS) $(SRC)/util.c
	mv *.o $(OBJ)/

clean:
	rm -f $(BIN)/glib_exe $(OBJ)/main.o $(OBJ)/util.o
 
	
