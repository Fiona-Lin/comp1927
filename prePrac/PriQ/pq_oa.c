// An implementaion of the Priority Queue ADT.
// This implementation uses an ordered array

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
} ;

PriQ initPriQ(void) {


}

//returns 1 if the pq is empty, 0 otherwise
int sizePriQ(PriQ q){

}

// add a new item into the queue
// O(n)
void insert(PriQ q, Item it) {

}

// delete the largest item
// O(1)
Item delMax(PriQ q) {

}
