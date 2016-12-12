//A linked list based implementation of a stack

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "Stack.h"

typedef struct stackNode StackNode;

struct stackNode { 
    Item item; 
    StackNode * next; 
};

struct stack{
    StackNode * top;
    int size;
};

Stack createStack (void){
    Stack s = malloc(sizeof(struct stack));
    assert(s != NULL); 
    s->top = NULL; 
    s->size = 0;
    return s;
}

void destroyStack(Stack stack){
    StackNode * curr, * next;
    assert(stack != NULL);
    curr = stack->top;
    while(curr!=NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(stack);
}

//Push an item onto the top of the stack
//The beginning of the linked list represents
//the top of the stack
void push (Stack stack, Item item){
   assert(stack != NULL); 
   StackNode *newNode = malloc(sizeof (StackNode));
   assert (newNode != NULL);

   newNode->item = item;

   newNode->next = stack->top;
   stack->top = newNode;
   stack->size++;
}

//Remove item from the top of stack
//Removes an item from the beginning of the linked list.
Item pop (Stack stack){ 
    assert(stack != NULL);
    assert(stack->top != NULL);

    Item item = stack->top->item;
    StackNode * top = stack->top;
    stack->top = top->next;
    stack->size--;
    free(top);
    return item;
}

int stackSize (Stack stack){ 
    return stack->size;
}
