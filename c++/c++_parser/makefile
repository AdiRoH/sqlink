CC = g++ 
CFLAGS = -ansi -pedantic -g
SRCS = Parser.cpp Tokenizer.cpp Analizer.cpp test.cpp 
OBJS = $(SRCS:.cpp=.o)
MAIN = file

all:$(MAIN)
	@echo excutable was created

$(MAIN):$(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)



