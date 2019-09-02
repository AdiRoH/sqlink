CFLAGS  = -fPIC
DFLAGS = -shared
doAll : libN.so prog

prog: progA.o progB.o
	gcc -L. -o prog progA.o progB.o -lN

progA.o : progA.c progB.h
	gcc -c -ansi -pedantic progA.c

progB.o : progB.c progB.h
	gcc -c -ansi -pedantic progB.c

libN.so : lib1.o lib2.o lib3.o libN.h
	gcc -shared -o libN.so lib1.o lib2.o lib3.o
	
lib1.o : lib1.c libN.h
	gcc -c $(CFLAGS) lib1.c

lib2.o : lib2.c libN.h
	gcc -c $(CFLAGS) lib2.c

lib3.o : lib3.c libN.h
	gcc -c $(CFLAGS) lib3.c
