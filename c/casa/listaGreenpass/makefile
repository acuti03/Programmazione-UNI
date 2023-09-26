greenpass: main.o functions.o
	gcc -g -o greenpass main.o functions.o

main.o: main.c headers.h
	gcc -g -c main.c

functions.o: functions.c headers.h
	gcc -g -c functions.c