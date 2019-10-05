CC = g++
FLAGS = -ansi -pedantic -g
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = file

all:$(MAIN)
	@echo excutable was created

$(MAIN):$(OBJS)
	$(CC) $(FLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)