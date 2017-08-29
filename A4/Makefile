CC = gcc

CFLAGS = -g -Wall
#CFLAGS = -O -Wall -pedantic
a4 : a4.o string.o sort.o

a4.o string.o sort.o : a4.h

a4.h : sort.h string.h
	touch a4.h

clean:
	rm -f *.o core a4

run: a4
	./a4