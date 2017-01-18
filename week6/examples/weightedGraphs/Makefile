CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY:	clean clobber

all: graphClient testPQ

%o:%c
	$(CC) $(CFLAGS) -c $<

graphClient: graphClient.o Graph_AdjMatrix.o pq_heap.o Item.o
	$(CC) -o graphClient graphClient.o Graph_AdjMatrix.o pq_heap.o Item.o

testPQ: testPQ.o pq_heap.o Item.o
	$(CC) -o testPQ testPQ.o pq_heap.o Item.o

clean:
	rm -f *.o core

clobber: clean
	rm -f graphClient
