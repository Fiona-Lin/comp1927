#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


//Recursive versions of functions

int length(link list){
    if(list == NULL) return 0;
    return 1 + length(list->next);
}

int sumOfElems(link list){
    if(list == NULL) return 0;
    return (list->item + sumOfElems(list->next));
}

void printListRec(link list){
    if(list != NULL){
        printf("%d ",list->item);
        printListRec(list->next);
    }
}

void printListRev(link list){
     if(list != NULL){
        printListRev(list->next);
        printf("%d ",list->item);           
    }
}


void printList(link list){
    link curr;
    curr = list;
    while(curr != NULL){
        printf("%d ",curr->item);
        curr = curr->next;
    }
    printf("\n");
}

link newList(){
    return NULL;
}

link newNode(Item item){
    link newNode = malloc(sizeof(struct node));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

//returns the node at the start of the list
//O(n)
link insertEnd(link list, link n){
    link curr = list;
    if(list == NULL){
        return n;
    } else {
        //find the end of the list
        while(curr->next != NULL){
            curr = curr->next;
        }
        //curr now points to the last element
        curr->next = n;
        return list;
    }
    
}

//O(1)
link insertFront(link list, link n){
    n->next = list;
    return n;
}

link deleteFirst(link list){
    if(list != NULL){
        link delNode = list;
        list = list->next;
        free(delNode);
    }
    return list;
}

link deleteItem(link list, Item item){
    link curr = list;
    link prev = NULL;
    while(curr != NULL && curr->item != item){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        //did not find item nothing to delete
        return list;
    //we are deleting the first node
    }else if(prev == NULL){
        list = list->next;
        free(curr);
        return list;
    } else {
        prev->next = curr->next;
        free(curr);
        return list;
    }
}
void freeList(link list){

}


