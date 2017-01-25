CC=gcc
CFLAGS=-Wall -Werror  -gdwarf-2
OBJS=graphClient.o GRAPH_adjlist.o Queue.o Stack.o

graphClient : $(OBJS)
	$(CC) -o graphClient $(OBJS)

graphClient.o : graphClient.c Graph.h

GRAPH_adjlist.o : GRAPH_adjlist.c Graph.h Queue.h
Queue.o : Queue.c Queue.h Item.h
Stack.o : Stack.c Stack.h Item.h

clean :
	rm -f glab $(OBJS) core *.dSYM
