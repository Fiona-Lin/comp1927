//An array based implementation of a stack

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Item.h"
#include "Stack.h"
#include "assert.h"

#define DEFAULT_SIZE 10

struct stackImp{
    Item * items;
    int top;
    int maxSize;
};

//A stack is created with a default initial size of 10
Stack createStack (void){
    Stack s = malloc(sizeof(struct stackImp));
    assert(s != NULL);
    s->items = malloc(DEFAULT_SIZE * sizeof(Item));
    assert(s->items != NULL);
    s->top = 0;
    s->maxSize = DEFAULT_SIZE;
    return s;
}

void destroyStack(Stack stack){
    assert(stack != NULL);
    free(stack->items);
    free(stack);
}

//You need to modify this
void push (Stack stack, Item item){
    assert(stack != NULL);
    if (stack -> top >= stack -> maxSize) {
        stack -> maxSize *= 2;
        stack -> items = realloc(stack -> items, sizeof(Item) * stack -> maxSize);
    }
    stack->items[stack->top] = item;
    stack->top++;
}

//You need to modify this
Item pop (Stack stack){
    assert(stack != NULL);
    if (stack -> maxSize > 10 && (stack -> maxSize)/4.0 == (stack -> top)) {
        stack -> maxSize *= 0.5;
        stack -> items = realloc(stack -> items, sizeof(Item) * stack -> maxSize);
    } else if (stack -> top == 0) {
        printf("stack underflow\n");
        abort();
    }
    stack->top--;
    return stack->items[stack->top];
}

int stackSize(Stack stack){
    assert(stack != NULL);
    return stack->top;
}

//You need to write these
void whiteBoxTests(void){
    printf("White box tests:\n");
    //test new stack is created
    printf("\n##Test create stack##\n");
    Stack s = createStack();
    assert(s != NULL);
    int size = s -> maxSize;
    assert(size == 10);
    printf("Max size of stack is:%d\n", size);
    printf("Passed!\n");
    //test push 10 item to stack
    printf("\n##Test pushing 10 items##\n");
    int i;
    for (i = 0; i < 10; i++) {
        printf("pushing: %d \n",i);
        push(s, i);
    }
    assert(s -> top == 10);
    printf("Passed!\n");
    //push the 11th item on to stack
    printf("\n##Test pushing 11th item##\n");
    push(s, i);
    printf("Expect stack's top = %d\nstack's top = %d\n", i + 1, stackSize(s));
    assert(s->top == 11);
    printf("Expect stack's size = 20\nstack's size = %d\n", s -> maxSize);
    assert(s->maxSize == 20);
    printf("\n##Test pushing another 10 items##\n");
    for (i = 11; i < 20; i++) {
        printf("pushing: %d \n",i);
        push(s, i);
    }
    printf("Passed!\n");
    printf("\n##Test pushing 21th item##\n");
    push(s, i);
    printf("Expect stack's top = %d\nstack's top = %d\n", i + 1, stackSize(s));
    assert(s->top == 21);
    printf("Expect stack's size = 40\nstack's size = %d\n", s -> maxSize);
    assert(s->maxSize == 40);
    printf("Passed!\n");
    //pop everything out
    printf("\n##Test poping 21 items##\n");
    for (; i > 0; i--) {
        printf("poping: %d \n",pop(s));
        if (i == 5 || i == 11) {
            printf("  ##Test reduce half size when popping to %d of %d stack\n",s->top, s->maxSize);
            printf("Expect stack's top = %d\nstack's top = %d\n", i , stackSize(s));
            if (i == 5) {
                assert(s -> top == 5);
                printf("Passed!\n");
            } else if (i == 11) {
                assert(s -> top == 11);
                printf("Passed!\n");
            }
            printf("reduce to size of %d stack\n", s -> maxSize );
            printf("Expect stack's size = %d\nstack's size = %d\n", s -> maxSize, (i-1)*4);
            if (i == 5) {
                assert(s -> maxSize == 20);
                printf("Passed!\n");
            } else if (i == 11) {
                assert(s -> maxSize == 40);
                printf("Passed!\n");
            }
        }
    }
    destroyStack(s);
    // printf("poping empty array, program is going to abort.\n");
    // pop(s);
}
