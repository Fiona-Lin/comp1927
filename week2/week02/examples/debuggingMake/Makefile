CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
OBJS=testList.o List.o

.PHONY: clean

all : useL fac fac1

useL : testList.o List.o
	$(CC) -o useL $(OBJS)

testList.o : testList.c List.h Item.h

List.o : List.c List.h Item.h

fac : fac.c

fac1 : fac1.c

clean :
	rm -f useL fac fac1 $(OBJS) core a.out
