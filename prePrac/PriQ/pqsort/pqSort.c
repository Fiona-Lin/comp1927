#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "pq.h"

void pqSort(Item a[], int lo, int hi) ;

void swap(int index1, int index2, int items[]);

int main(void){
    int size;
    int i;
    printf("Enter number of elements:");
    scanf("%d",&size);

    int * a = malloc(size * sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<size;i++){
	    scanf("%d",&a[i]);
    }

    pqSort(a,0,size-1);

    printf("Sorted\n");
    for(i=0;i<size;i++){
            printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}

void pqSort(Item a[], int lo, int hi) {
   // put items into PQ
   // remove items from PQ
}

void swap(int index1, int index2, int items[]){

}

