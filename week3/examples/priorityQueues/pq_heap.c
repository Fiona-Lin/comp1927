// A heap-array based implementation of a priority queue

#include <stdlib.h>
#include <assert.h>

#include "Item.h"
#include "pq.h"

#define DEFAULT_MAX 100

struct pqImp { 
    int nItems;     // count of items 
    Item *items;   // heap-array of Items 
    int size;     // size of array 
} ;

//Create a new empty priority queue
PriQ initPriQ(void) { 
    PriQ q = malloc(sizeof(struct pqImp)); 
    assert(q != NULL); 
    q->size = DEFAULT_MAX;
    // indexes start from 1 
    q->items = malloc(sizeof(Item) * (q->size+1));
    assert(q->items != NULL); 
    q->nItems = 0;
    return q; 
}

int sizePriQ(PriQ pq){
    return (pq->nItems);
}

// A local helper function to swap the item from index1 and index2 in the array
static void swap(Item a[],int index1,int index2){
   Item tmp;
   tmp = a[index1];
   a[index1] = a[index2];
   a[index2] = tmp;
}

// Local function - not part of the interface
// Bottom up heapify
// force value at a[k] into correct position 
void fixUp(Item a[], int k) { 
    while (k > 1 && less(a[k/2],a[k])) { 
        swap(a, k, k/2); 
        k = k/2; // integer division 
    } 
} 

// Top down heapify
// force value at a[k] into correct position 
void fixDown(Item a[], int k, int N) {
   int done = 0;
   while (2*k <= N && !done) { 
       int j = 2*k; //choose larger of two children 
       if (j < N && less(a[j], a[j+1])){
           j++;
       } 
       if (!less(a[k], a[j])){
           done =1;
       }else{ 
           swap(a, k, j); 
           k = j;
       } 
   } 
} 

// add a new item into the queue 
void insert(PriQ q, Item it) { 
    assert(q != NULL && q->nItems < q->size); 
    q->nItems++; 
    q->items[q->nItems] = it; 
    fixUp(q->items, q->nItems); 
} 

// delete the highest priority item 
Item delete(PriQ q) { 
    assert(q != NULL && q->nItems > 0); 
    swap(q->items, 1, q->nItems); 
    
    q->nItems--; 
    fixDown(q->items, 1, q->nItems); 
    return q->items[q->nItems+1]; 
} 
