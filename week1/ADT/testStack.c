#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Item.h"
#include "Stack.h"

void whiteBoxTest(void);

int main(int argc, char * argv[]){
    int j;
    whiteBoxTest();
    printf("Test 1: Create a stack\n");
    Stack s = createStack();
    assert(s != NULL);
    assert(stackSize(s) == 0);
    
    //assert(s->numItems == 0);
    
    printf("Passed\n");

    printf("Test 2: Push 3\n");
    push(s,3);
    assert(stackSize(s) == 1);
    Item i = pop(s);
    assert(i == 3);
    printf("Passed\n");

    printf("Test 3: Push lots of stuff\n");
    for(j=0; j < 100; j++){
        push(s,j);
    }
    assert(stackSize(s) == 100);
    for(j=99; j>=0; j--){
        i = pop(s);
        assert(i == j);
    }
    printf("Passed\n");


    return 0;
}

