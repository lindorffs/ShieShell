CC=gcc
CFLAGS=-I../include/
DEPS=shell.h builtin.h
OBJ= main.o shell.o builtin/cd.o builtin/env.o builtin/set.o builtin/version.o
BIN=../bin/shieshell
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean: $(OBJ) $(BIN)
	rm -rfv $^
