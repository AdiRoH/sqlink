CC = g++
FLAGS = -ansi -pedantic -g

SRCS = memPage.cpp memPool.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = prog
all: $(MAIN)
	@echo prog was compiled and linked
$(NAIN):$(OBJS)
	$(CC) $(FLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
