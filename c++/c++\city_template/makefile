CC = g++
FLAGS = -ansi -pedantic -g

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

MAIN = prog

all:$(MAIN)
	@echo "executed"

$(MAIN):$(OBJS)
	$(CC) $(FLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)


