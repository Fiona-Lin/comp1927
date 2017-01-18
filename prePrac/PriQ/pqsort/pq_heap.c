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
   // indexes start from 1
}

int sizePriQ(PriQ pq){

}

// A local helper function to swap the item from index1 and index2 in the array
static void swap(Item a[],int index1,int index2){

}

// Local function - not part of the interface
// Bottom up heapify
// force value at a[k] into correct position
void fixUp(Item a[], int k) {

}

// Top down heapify
// force value at a[k] into correct position
void fixDown(Item a[], int k, int N) {


}

// add a new item into the queue
void insert(PriQ q, Item it) {

}

// delete the highest priority item
Item delete(PriQ q) {

}
