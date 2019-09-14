fdup : MD5_calculator.o wqueue.o DirWalk.o H_Hash.o FindDuplicate.o 
	gcc -o fdup MD5_calculator.o wqueue.o DirWalk.o H_Hash.o FindDuplicate.o -lcrypto -lssl -pthread

MD5_calculator.o : MD5_calculator.c MD5_calculator.h
	gcc -g -c -ansi -pedantic MD5_calculator.c

DirWalk.o : DirWalk.c wqueue.h DirWalk.h 
	gcc -g -c -ansi -pedantic -pthread DirWalk.c

H_Hash.o : H_Hash.c H_Hash.h
	gcc -g -c -ansi -pedantic H_Hash.c

FindDuplicate.o : FindDuplicate.c DirWalk.h H_Hash.h MD5_calculator.h wqueue.h
	gcc -g -c -ansi -pedantic FindDuplicate.c

wqueue.o  : wqueue.c wqueue.h
	gcc -g -c -ansi -pedantic wqueue.c