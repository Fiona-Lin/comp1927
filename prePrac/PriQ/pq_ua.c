// An implementaion of the Priority Queue ADT.
// This implementation uses an unordered array

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "pq.h"

#define DEFAULT_MAX 100

struct pqImp {
   int nItems;  // count of items
   Item *items; // array of Items
   int size;    // size of array
};

PriQ initPriQ(void) {

}

int sizePriQ(PriQ pq){

}

// add a new item into the queue
// O(1)
void insert(PriQ q, Item it) {

}

// A local helper function to swap the item from index1 and index2
// in the array
static void swap(Item a[],int index1,int index2){

}

// delete the largest item
// O(n)
Item delMax(PriQ q) {

}
