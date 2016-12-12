//A linked list based implementation of a stack

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "Stack.h"

typedef struct stackNode StackNode;

struct stackNode{
    Item item;
    StackNode * next;
};

struct stack{
    StackNode * top;
    int size;
};

Stack createStack (void){
    Stack s = malloc(sizeof(struct stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void destroyStack(Stack stack){
    if(stack == NULL) return;
    //Free linked list in the stack
    StackNode * curr = stack->top;
    StackNode * next = NULL;

    while(curr!= NULL){
        next = curr->next;
        free(curr);
        curr=next;
    }
    free(stack);
}

//Push an item onto the top of the stack
//The beginning of the linked list represents
//the top of the stack
void push (Stack stack, Item item){
   //create a new node
   StackNode * newNode = malloc(sizeof(StackNode));
   newNode->item = item;
   newNode->next = NULL; //Not really needed but good habit

   //add it to the beginning of the list
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
    
    //Remove from the list and free
    StackNode * tmp = stack->top;
    stack->top = tmp->next;
    free(tmp);
    
    stack->size--;
    return item;
}

int stackSize (Stack stack){ 
   return stack->size;
}

