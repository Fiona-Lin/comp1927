// Stack.h ... interface to Stack ADT
// Written by John Shepherd, March 2013

#include "Bool.h"
#include "Item.h"

typedef struct StackRep *Stack;

// set up empty stack
Stack newStack();

// remove unwanted stack
void dropStack(Stack);

// insert an Item on top of stack
void StackPush(Stack,Item);

// remove item from top of stack
Item StackPop(Stack);

// check whether stack is empty
Bool StackIsEmpty(Stack);

