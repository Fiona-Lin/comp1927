
# COMP1927 assignment 1

CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
.PHONY: clean clobber

all: testBuffer testTextBuffer.o textbuffer.o

testBuffer: testTextBuffer.o textbuffer.o
	$(CC) -o testBuffer  testTextBuffer.o textbuffer.o

testTextBuffer.o: testTextBuffer.c textBuffer.h
	$(CC) -c $(CFLAGS) testTextBuffer.c

textbuffer.o: textbuffer.c
	$(CC) -c $(CFLAGS) textbuffer.c

clean:
	rm -f *.o

clobber: clean
	rm testStack testListQueue testArrayQueue
