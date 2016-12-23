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
    int i; 
    PriQ q = initPriQ(); 
    // put items into PQ 
    for (i = lo; i <= hi; i++){ 
        insert(q, a[i]); 
    }
    // remove items from PQ 
    for (i = hi; i >= lo; i--){ 
        a[i] = delete(q); 
    }
}

void swap(int index1, int index2, int items[]){
    int tmp;
    tmp = items[index1];
    items[index1] = items[index2];
    items[index2] = tmp;
}

