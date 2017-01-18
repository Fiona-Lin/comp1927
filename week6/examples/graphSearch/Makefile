CC=gcc
CFLAGS=-Wall -Werror -g
OBJS=graphClient.o Graph_AdjMatrix.o Queue.o Stack.o

graphClient : $(OBJS)
	$(CC) -o graphClient $(OBJS)

graphClient.o : graphClient.c Graph.h

Graph_AdjMatrix.o : Graph_AdjMatrix.c Graph.h Queue.h
Queue.o : Queue.c Queue.h Item.h
Stack.o : Stack.c Stack.h Item.h

clean :
	rm -f glab $(OBJS) core *.dSYM
