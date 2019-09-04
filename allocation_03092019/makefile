CFLAGS  = -ansi -pedantic -g -Wall 

file : allocation.o UnitTest.o
	gcc -o file allocation.o UnitTest.o

allocation.o : allocation.c allocation.h
	gcc $(CFLAGS) allocation.c

UnitTest.o : UnitTest.c allocation.h
	gcc $(CFLAGS) UnitTest.c
