prog: Test.o wqueue.o producers.o consumers.o
	gcc -o prog Test.o wqueue.o producers.o consumers.o -pthread -lrt

wqueue.o : wqueue.c wqueue.h
	gcc -g -c -pthread -ansi -pedantic wqueue.c -lrt 

Test.o : Test.c wqueue.h
	gcc -g -c -pthread -ansi -pedantic Test.c -lrt

producers.o : producers.c wqueue.h
	gcc -g -c -pthread -ansi -pedantic producers.c -lrtquit

pconsumers.o : pconsumers.c wqueue.h
	gcc -g -c -pthread -ansi -pedantic consumers.c -lrtquit