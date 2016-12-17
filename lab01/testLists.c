#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

// insert proper tests here
int main (int argc, const char * argv[]) {
    // A sample test for creating circular linked test has been provided below.

    int num_nodes;
    if (argc < 2) {
        printf("Enter number of nodes for circular list:\n"); return 0;
    }

    sscanf(argv[1],"%d",&num_nodes);
    printf("No of nodes = %d \n", num_nodes);
    link start = create_circular_list(num_nodes);
    // A sample test for printing the nodes of the circular list from the second node
    print_nodes(start->next);
    freeList(start);
    int i = 0;
    int sum;
    while(i < 5) {
        start = create_circular_list(i);
        sum = sumListItems(start);
        printf("The sum for node of %d is: %d \n", i, sum);
        freeList(start);
        i++;
    }
    start = create_circular_list(num_nodes);
    dlink dstart = doublify(start);
    printf("The double linked list test: \n");
    while(dstart->next != NULL) {
        printf("[%d]->",dstart->item);
        dstart = dstart -> next;
    }
    while(dstart->prev != NULL) {
        printf("[%d]<-",dstart->item);
        dstart = dstart -> prev;
    }
    printf("[%d]<-",dstart->item);
    printf("[x]\n");
    freeDList(dstart);
    freeList(start);
    
    return 0;
}
