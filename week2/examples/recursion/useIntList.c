// useIntList.c - testing IntList data type

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "IntList.h"

int main(int argc, char *argv[]){
    IntList myList;

    printf("Type in numbers to insert into the list and hit ctrl d\n");   
    //Read in the list till you get Ctrl d 
    myList = fScanIntList(stdin);
    
    printf("Printing list recusively\n");
    recursivePrint(myList);
    printf("\n");
    printf("Printing list backwards recursively\n");
    recursivePrintReverse(myList);    
    printf("\n");

    recursivePrint(myList);
    printf("\n");
    //freeIntList(myList);
    return 0;
}
