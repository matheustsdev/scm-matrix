all: main.e

main.e: main.o pgm.o utils.o
	gcc -o main.e main.o -lm pgm.o utils.o 

main.o: main.c
	gcc -o main.o -c main.c -lm

pgm.o: pgm.c
	gcc -o pgm.o -c pgm.c

utils.o: utils.c
	gcc -o utils.o -c utils.c

start:
	./main.e 8
	
clean:
	rm *.o *.txt main.e -r