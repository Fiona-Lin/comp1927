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
    PriQ ret = calloc(sizeof(struct pqImp), 1);
    ret -> size = DEFAULT_MAX;
    ret -> items= calloc(sizeof(Item), DEFAULT_MAX);
    return ret;
}

int sizePriQ(PriQ pq){
    return (pq->nItems);
}

// A local helper function to swap the item from index1 and index2 in the array
static void swap(Item a[],int index1,int index2){
    Item temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

// Local function - not part of the interface
// Bottom up heapify
// force value at a[k] into correct position
void fixUp(Item a[], int k) {
    while(k > 1 && less(a[k/2], a[k])) {
        swap(a, k/2, k);
        k = k/2;
    }
}

// Top down heapify
// force value at a[k] into correct position
void fixDown(Item a[], int k, int N) {
    int done = 0;
    while (!done && 2 * k <= N) {
        int j = 2 * k + 1;//get the left child
        if (less(a[j], a[j+1])) { // compare and find the larger child
            j++;
        }
        if (less(a[k],a[j])) {
            swap(a, k, j);
            k = j;
        } else {
            done = 1;
        }
    }
}

// add a new item into the queue
void insert(PriQ q, Item it) {
    if(q == NULL) {
        q = initPriQ();
        q -> items[0] = it;
        q -> nItems ++;
    } else {
        if(q -> nItems < q -> size) {
            q -> items[q -> nItems] = it;
            fixUp(q -> items, q -> nItems);
            q -> nItems ++;
        }
    }
}

// delete the highest priority item
Item delete(PriQ q) {
    Item ret = NULL;
    if (q != NULL) {
        q -> nItems --;
        swap(q -> items, 0, q -> nItems);
        fixDown(q -> items, 0, q -> nItems);
        ret = q -> items[q -> nItems];
    }
    return ret;
}
