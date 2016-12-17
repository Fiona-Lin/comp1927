#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "Queue.h"
#include <assert.h>

#define DEFAULT_SIZE 10

struct queueImp{
    Item *items;
    int size;
    int end;
    int start;
    int maxSize;
};

//O(1)
Queue createQueue(){
    Queue q = malloc(sizeof(struct queueImp));
    q->items = malloc(DEFAULT_SIZE * sizeof(Item));
    q->size =0;
    q->start =0;
    q->end =0;
    q->maxSize = DEFAULT_SIZE;
    return q;
}

void destroyQueue(Queue q){
    assert(q != NULL);
    free(q->items);
    free(q);
}

//O(1)
int queueSize(Queue q){
    assert(q != NULL);
    return (q->size);
}

//O(1);
void putQueue(Queue q, Item i){
    assert(q != NULL);
    if (q->size < q->maxSize) {
        int index = q -> end++ % 10;
        q->items[index]  = i;
        q->size++;
    } else {
        printf("Queue Overflow");
        abort();
    }
}

//O(n)
Item getQueue(Queue q){
    assert(q != NULL);
    if(q->size > 0){
        int index = q -> start++ % 10;
        Item item = q->items[index];
        q->size--;
        //shift the elements across
        return item;
    } else {
        fprintf(stderr,"queue underflow\n");
        abort();
    }
}

void queueWhiteBoxTests(void){
    printf("White box tests not done\n");
}
