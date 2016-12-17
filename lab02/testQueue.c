#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Item.h"
#include "Queue.h"

void queueWhiteBoxTests(void);
int main (int argc, char *argv[]){
    //Run white box tests
    queueWhiteBoxTests();

    //Run black box tests
    printf("Black Box tests:\n");

    printf("Test 1: createQueue\n");
    Queue q = createQueue();
    assert(q != NULL);
    assert(queueSize(q) == 0);
    printf("Passed\n");

    printf("Test 2: put more than 10 items to Queue\n");
    int i = 0;
    while (i < 10) {
        printf("put %d to queue\t", i);
        putQueue(q, i);
        printf("The size of queue: %d\n", queueSize(q));
        i++;
    }
    assert(queueSize(q) == i);
    printf("Passed\n");

    printf("Test 3: get queue\n");
    i = 0;
    //while (i < 11) { //aborted successfully
    while (i < 10) {
        printf("get %d from queue\t", getQueue(q));
        printf("The size of queue: %d\n", queueSize(q));
        i++;
    }
    assert(queueSize(q) == 0);
    printf("Passed\n");

    printf("Test 4: put and get queue repeatly more than 10 times\n");
    i = 0;
    while (i < 3) {
        printf("put %d to queue\t", i);
        putQueue(q, i);
        printf("The size of queue: %d\n", queueSize(q));
        i++;
    }
    while (i < 13) {
        printf("put %d to queue\t", i);
        putQueue(q, i);
        printf("The size of queue: %d\n", queueSize(q));
        printf("get %d from queue\t", getQueue(q));
        printf("The size of queue: %d\n", queueSize(q));
        i++;
    }
    while (i < 21) {
        printf("put %d to queue\t", i);
        if(i == 20) {
            printf("Current queue size %d\n", queueSize(q));
            printf("Abort expected.\n");
        }
        putQueue(q, i);
        printf("The size of queue: %d\n", queueSize(q));
        if(i == 19) {
            assert(queueSize(q) == 10);
            printf("Passed\n");
        }
        i++;
    }


    // Tested, aborted successfully
    // printf("get from empty queue, program is going to abort\n");
    // getQueue(q);

    destroyQueue(q);
    return 0;
}
