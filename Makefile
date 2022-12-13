all: main.e

main.e: main.o pgm.o scm.o utils.o
	gcc -o main.e main.c pgm.o scm.o utils.o

main.o: main.c
	gcc -o main.o -c main.c

pgm.o: pgm.c
	gcc -o pgm.o -c pgm.c

scm.o: scm.c
	gcc -o scm.o -c scm.c

utils.o: utils.c
	gcc -o utils.o -c utils.c

start:
	./main.e