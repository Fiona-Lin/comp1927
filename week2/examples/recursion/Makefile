# COMP1927

CC=gcc
CFLAGS=-Wall -Werror -O

all: factorial badFib goodFib useIntList recursiveMax useList

factorial: factorial.o
	$(CC) $(CFLAGS) -o factorial factorial.o

factorial.o: factorial.c
	$(CC) $(CFLAGS) -c factorial.c

badFib: badFib.o
	$(CC) $(CFLAGS) -o badFib badFib.o

badFib.o: badFib.c
	$(CC) $(CFLAGS) -c badFib.c

goodFib: goodFib.o
	$(CC) $(CFLAGS) -o goodFib goodFib.o

goodFib.o: goodFib.c
	$(CC) $(CFLAGS) -c goodFib.c

lists.o: lists.c lists.h
	$(CC) $(CFLAGS) -c lists.c

useList: useList.o lists.o
	 $(CC) $(CFLAGS) -o useList useList.o lists.o

useList.o: useList.c
	$(CC) $(CFLAGS) -c useList.c

useIntList: useIntList.o IntList.o
	$(CC) $(CFLAGS) -o useIntList useIntList.o IntList.o

useIntList.o: useIntList.c
	$(CC) $(CFLAGS) -c useIntList.c

IntList.o: IntList.c
	$(CC) $(CFLAGS) -c IntList.c 

recursiveMax: recursiveMax.o
	$(CC) $(CFLAGS) -o recursiveMax recursiveMax.o

recursiveMax.o: recursiveMax.c
	$(CC) $(CFLAGS) -c recursiveMax.c

clean:
	rm -f *.o
clobber: clean
	rm -f factorial badFib goodFib useIntList recursiveMax useList
	
