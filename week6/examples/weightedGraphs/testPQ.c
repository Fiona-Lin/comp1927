#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "Item.h"
#include "pq.h"

int main(int argc, char * arv[]){
    PriQ pq = initPriQ(100);
    int i;
    for(i=0;i<10;i++){
      insert(pq,newItem(FLT_MAX,i));
    }
    printf("decrease priority and delMin\n");
    decreaseWeight(pq,5,2);
    decreaseWeight(pq,1,10);
    decreaseWeight(pq,9,0);
    Item i1 = delMin(pq);
    printf("delMin %d\n",i1->value);
    assert(i1->value == 9);
    assert(i1->keyVal == 0);
    printf("Passed\n");
    printf("delMin more\n");
    Item i2 = delMin(pq);
    assert(i2->value == 5);
    assert(i2->keyVal == 2);
    Item i3 = delMin(pq);
    assert(i3->value == 1);
    assert(i3->keyVal == 10);
    printf("Passed\n");
    
    decreaseWeight(pq,7,1);
    Item i4 = delMin(pq);
    assert(i4->value == 7);
    assert(i4->keyVal == 1);
    printf("Passed\n");


    return 0;
}
