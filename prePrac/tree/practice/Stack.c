// Stack.c
// array implementation of Stack DT
// Written by John Shpherd, March 2013

#include <stdlib.h>
#include <assert.h>
#include "Bool.h"
#include "Item.h"
#include "Stack.h"

#define MAXITEMS 10

typedef struct StackRep {
    Item item[MAXITEMS];
    int  top;
} StackRep;

// set up empty stack
Stack newStack() {

}


// remove unwanted stack
void dropStack(Stack s) {

}

// insert char on top of stack
void StackPush(Stack s, Item it) {

}

// remove item from top of stack
Item  StackPop(Stack s) {

}

// check whether stack is empty
Bool StackIsEmpty(Stack s) {

}
