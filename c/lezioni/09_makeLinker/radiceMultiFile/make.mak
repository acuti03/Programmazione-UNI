main.o: main.c headers.h
	gcc -c main.c

rdq.o: rdq.c headers.h
	gcc -c rdq.c

exe: main.o rdq.o
	gcc -o exe main.o rdq.o
