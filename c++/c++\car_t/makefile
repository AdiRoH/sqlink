CC = g++
CFLAGS = -ansi -pedantic -g
SRCS = car.cpp test.cpp
OBJS = $(SRCS:.c=.o)
MAIN = prog

all: $(MAIN)
	@echo program named 'prog' was compiled and linked

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@
clean:
	$(RM) *.o *~ $(MAIN)

