CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2

all: graph

#graph: GRAPH_adjlist.o graphClient.o
#	$(CC) $(CFLAGS) -o graph GRAPH_adjlist.o graphClient.o

graph: nich.o graphClient.o
	$(CC) $(CFLAGS) -o graph nich.o graphClient.o
graphClient.o: graphClient.c GRAPH.h

#GRAPH_adjlist.o: GRAPH_adjlist.c GRAPH.h
nich.o: nich.c GRAPH.h

clobber: clean
	rm -f graph
clean:
	rm -f core *.o
