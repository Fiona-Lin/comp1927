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
} ;

PriQ initPriQ(void) { 
   PriQ q = malloc(sizeof(struct pqImp)); 
   assert(q != NULL); 
   q->size = DEFAULT_MAX;
   q->items = malloc(sizeof(Item) * q->size); 
   assert(q->items != NULL); 
   q->nItems = 0; 
   return q; 
} 

int sizePriQ(PriQ pq){
    return (pq->nItems);
}

// add a new item into the queue 
// O(1)
void insert(PriQ q, Item it) { 
    assert(q != NULL && q->nItems < q->size); 
    q->items[q->nItems] = it; 
    q->nItems++; 
}

// A local helper function to swap the item from index1 and index2 
// in the array
static void swap(Item a[],int index1,int index2){
   Item tmp;
   tmp = a[index1];
   a[index1] = a[index2];
   a[index2] = tmp;
}

// delete the largest item 
// O(n)
Item delMax(PriQ q) { 
    assert(q != NULL && q->nItems > 0); 
    Item *a = q->items; 
    int i, max = 0, n = q->nItems-1; 
    for (i = 1; i <= n; i++){ 
      if (less(a[max],a[i])){ 
          max = i; 
      }
    }
    swap(a, max, n); 
    q->nItems = n; 
    return a[n]; 
} 
 



