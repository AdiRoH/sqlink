CC = g++
CFLAGS = -ansi -pedantic -g
SRCS = AD_H.cpp meet.cpp test.cpp
OBJS = $(SRCS:.cpp =.o)

MAIN = prog

all:$(MAIN)
	@echo "executed"

$(MAIN):$(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)


