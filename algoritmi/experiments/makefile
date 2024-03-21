CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pedantic

all: exe
	./exe

exe: main.o
	$(CC) -o exe main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c