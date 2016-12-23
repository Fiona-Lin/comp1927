// List.c ... implementation of List ADT as linked-list
// Written by John Shepherd, March 2013

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Item.h"
#include "List.h"

typedef struct Node *Link;

typedef struct Node {
	Item value;
	Link next;
} Node;

typedef struct ListRep {
	Node *first;  // ptr to first node
	Node *last;   // ptr to last node
	Node *curr;   // current node in scan
} ListRep;

// create new empty list
List newList()
{
        
	List L;
	L = malloc(sizeof(ListRep));
	assert(L != NULL);
	L->first = NULL;
	L->last = NULL;
	L->curr = NULL;
	L->first = NULL;
        return L;
}

// free memory used by list
void dropList(List L)
{
	Node *next;
	while (L->first != NULL) {
		next = L->first->next;
		ItemDrop(L->first->value);
		free(L->first);
		L->first = next;
	}
	free(L);
}

// display as [1,2,3,4...]
void showList(List L)
{
	Node *curr;
	printf("[");
	curr = L->first;
	while (curr->next != NULL) {
		ItemShow(curr->value);
		if (curr->next != NULL)
			printf(",");
		curr = curr->next;
	}
	printf("]");
}

// read+insert list values
List readList()
{
	Item val;
	List new = newList();
	while (ItemRead(&val)) {
		ListInsert(new, val);
	}
	return new;
}

// make a copy of a list
List ListCopy(List L)
{
	List new = newList();
	Link cur = L->first;
	while (cur != NULL) {
		ListInsert(new, cur->value);
		cur = cur->next;
	}
	return new;
}

// add item into list
void ListInsert(List L, Item it)
{
	Link new;
	new = malloc(sizeof(Node));
	assert(new != NULL);
	new->value = ItemCopy(it);
    new->next = NULL;
	if (L->last == NULL) {
		L->first = new;
	}
	else {
		L->last->next = new;
	}
	L->last = new;
}

// remove item(s)
void ListDelete(List L, Item it)
{
	return;
}

// get i'th item
Item ListItem(List L, int i)
{
	return 0;
}

// position of item
int ListFindPos(List L, Item it)
{
	return -1;
}

// # items in list
int ListLength(List L)
{
	int nnodes = 0;
	Link curr = L->first;
	while (curr != NULL) {
		nnodes++;
		curr = curr->next;
	}
	return nnodes;
}

// begin scan
void ListStartScan(List L)
{
}

// fetch next element
Item ListScanNext(List L)
{
	return 0;
}

// reached end of scan?
int ListScanDone(List L)
{
	return 1;
}


#endif
