//Priority Queue: Basic idea
#include <stdlib.h>
#include "PriQ.h"

#define DEFAULTSIZE 10

typedef int Key;    //Can change key type

typedef struct record * Item;

struct record{
    Key keyVal;
    char * value;      //Can change value type
};


struct pqImp {
   int nItems;  // count of items
   Item *items; // array of Items
   int size;    // size of array
} ;

// Core operations

static Item newItem(Key k,char * v){
    Item i = malloc(sizeof(struct record));
    assert(i != NULL);
    i->keyVal = k;
    i->value = v;
    return i;
}

PriQ initPriQ(void){
   PriQ ret = calloc(sizeof(struct qpImp),1);
   ret -> size = DEFAULTSIZE;
   ret -> items = calloc(sizeof(struct record), ret->size);
   return ret;
}

void insert(PriQ q, Item i) {
   if (q == NULL) {
      q = initrPriQ();
   }
   q -> items[q -> nItems] = i;
   (q -> size)++;
}

Item delete(PriQ q) {
  int
  if (q != NULL) {
    int key = q -> items[0] -> keyVal;

  }
}
// Useful operations
int sizePriQ(PriQ q) {
  return q -> nItems;

}
void change(PriQ q, Key k, Item i) {

}
void deleteKey(PriQ q, Key k) {

}

PriQ join(PriQ q1, PriQ q2) {

}

int maxSize(PriQ q) {
  return q -> size;
}

// [value, key = 3] -> [value, key = 8]
// -> [value, key = 7]
// If we choose highest key as priority, then we’d take the middle one first, followed by the last, and finally the first.


// // So we want something like a regular queue, except the only difference is that we output the highest ‘priority’ element instead. Each queue element at least has: a value - the thing we want to store, and a key - the thing which determines its priority.

// PriQ initPriQ(void){
//    calloc(sizeof(*char * 1), 1);
//    return a[];
// }

// PriQ AppendPriQ(PriQ q, Item i) {
//   //realloc extra spot
//   //insert at end}

// PriQ RetrievePriQ(PriQ q, Item i){
//   while(q[count]->item != i){
//     count++;
//   }
//   return *q[count]->item;
// }
