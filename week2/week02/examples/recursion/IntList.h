// IntList.h - Lists of integers (interface)
// Written by John Shepherd, July 2008
// Modified by Angela Finlayson, November, 2008

#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>

// External view of IntList
// Implementation given in intList.c

typedef struct intListImp *IntList;

// create a new empty IntList
IntList newIntList(void);

// free up all space associated with list
void freeIntList(IntList);

// create an IntList by reading values from a file
// assume that the file is open for reading
IntList fScanIntList(FILE *);

// apppend one integer to the end of a list
void insertIntList(IntList, int);

// delete first occurrence of v from a list
// if v does not occur in List, no effect
void deleteIntList(IntList, int);

// display list as one integer per line on stdout
void printIntList(IntList);

void reverse(IntList);

//Return 1 if the given int is in the list
//and 0 otherwise
int find(IntList,int); 

void largestLast(IntList);

void smallestFirst(IntList);

//Some recursive list functions
int count(IntList l);
void recursivePrint(IntList l);
void recursivePrintReverse(IntList l);
//delete the first occurrence of v
void recursiveDelete(IntList l, int v);
//Insert at the end of the list
void recursiveInsert(IntList l, int v);

void mergeSort(IntList l);

#endif
