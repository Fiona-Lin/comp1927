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
   PriQ q = malloc(sizeof(struct pqImp)); 
   assert(q != NULL); 
   q->size = DEFAULT_MAX;
   q->items = malloc(sizeof(Item) * q->size); 
   assert(q->items != NULL); 
   q->nItems = 0; 
   q->size = size; 
   return q; 
} 

//returns 1 if the pq is empty, 0 otherwise
int sizePriQ(PriQ q){
    return (q->nItems);
}

// add a new item into the queue
// O(n)
void insert(PriQ q, Item it) { 
    assert(q != NULL && q->nItems < q->size); 
    Item *a = q->items; 
    int i, j, n = q->nItems; 
    //Find index where item belongs in array
    for (i = 0; i < n && greaterThan(it,a[i]); i++); 
               
    for (j = n; j > i; j--) {
        a[j] = a[j-1]; // push up
    }    
    a[i] = it; 
    q->nItems++; 
} 

// delete the largest item 
// O(1)
Item delMax(PriQ q) { 
    q->nItems--; 
    return q->items[q->nItems]; 
} 
