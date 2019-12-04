CFLAGS = -g3 -pedantic -pthread -O2 -Werror -Wall

all:server serverThreads serverEpoll

server: server.c
	gcc $(CFLAGS) -o $@ $<

serverThreads: serverThreads.c
	gcc $(CFLAGS) -o $@ $<

serverEpoll: serverEpoll.c

.PHONY:clean
clean:
	rm -f server
	rm -f serverThreads
	rm -f serverEpoll
