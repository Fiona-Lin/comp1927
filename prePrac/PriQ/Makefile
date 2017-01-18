CC = gcc
CFLAGS = -Wall -Werror -gdwarf-2

.PHONY:	clean clobber

all: usePQ

%o:%c
	$(CC) $(CFLAGS) -c $<

usePQ: pq_heap.o usePQ.o Item.o
	$(CC) -o usePQ pq_heap.o usePQ.o Item.o

clean:
	rm -f *.o core

clobber: clean
	rm -f usePQ
