// An array based implementation of a stack
// This version has 2 major BUGS. It pushes and overfills the array
// It pops even when the stack is empty and tries to access array at index 
// -1
// Please see the solutions to lab03 for a better implementation that 
// deals with these issues

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Item.h"
#include "Stack.h"
#include "assert.h"

#define DEFAULT_SIZE 100

struct stack{
    Item * items; //Array
    int numItems; //How many items are in our stack?
    int maxSize;  //What is the capacity
};



Stack createStack (void){
    Stack s = malloc(sizeof(struct stack));
    assert(s != NULL);

    s->items = malloc(DEFAULT_SIZE * sizeof(Item));
    assert( s->items != NULL);

    s->numItems = 0;
    s->maxSize = DEFAULT_SIZE;
    return s;
}

//UNSAFE CODE BUFFER OVERFLOW
void push (Stack stack, Item item){ 
    assert(stack != NULL);
    stack->items[stack->numItems] = item;
    stack->numItems++;

}

//SHOULD CHECK STACK NOT EMPTY
Item pop (Stack stack){ 
    assert(stack != NULL);
    stack->numItems--;
    return stack->items[stack->numItems];
    
}

int stackSize(Stack stack){
    assert(stack != NULL);
    return stack->numItems;
}




void destroyStack(Stack stack){
    if(stack != NULL){
        if(stack->items != NULL){
            free(stack->items);
        }
        free(stack);
    }
    
}

void whiteBoxTest(void){
    printf("Whitebox test\n");
    Stack s = createStack();
    assert(s->numItems == 0);
    assert(s->maxSize == 100);
    printf("passed\n");

    ///blah blah

}

