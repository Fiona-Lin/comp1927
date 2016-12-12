#include <stdlib.h>
#include <stdio.h>
#include "lists.h"



void deleteNext(link curr){
    if(curr != NULL){
        link delNode = curr->next;
        if(delNode != NULL){
            curr->next = delNode->next;
            free(delNode);   
        }
    }
}

link deleteFirstItem(link list){
    
    if(list != NULL){
        link delNode = list;
        list = list->next;
        free(delNode);
    } 
    return list;
}

void printList(link list){
    link curr;
    for(curr = list; curr != NULL; curr= curr->next){
        printf("%d ",curr->item);
    }
    printf("\n");
}

link newList(){
    return NULL;
}

link newNode(Item item){
    link n = (link) malloc(sizeof(*n));
    n->item = item;
    n->next = NULL;
    return n;
}

//O(n)
link insertEnd(link list, link n){
    link curr;
    if(list == NULL){
        list = n;
    } else {
        for(curr = list; curr->next != NULL; curr = curr->next){
    
        }
        curr->next = n;
    }
    return list;
}

//O(1)
link insertFront(link list, link n){
   n->next = list;
   return n;
}

// These functions were created to demonstrate the use of function pointers

void printNode(link ls){
    if(ls != NULL){
        printf("%d->",ls->item);
    }
}

void printGrade(link ls){
    if(ls != NULL){
        if(ls->item >= 85){
            printf("HD ");
        } else {
            printf("FL ");
        }
    }
}

int isOdd(Item item){
    return (item%2 != 0);
}

int isNegative(Item item){
     return (item < 0);
}

int isFail(Item item){
     return (item < 50);
}


void traverseIf(link ls, int (*f) (Item)){
    link curr;
    for(curr = ls; curr!= NULL; curr = curr->next){
        if((*f) (curr->item)){
            printf("%d ",curr->item);
        }
    }
    printf("\n");
}

void traverse(link ls, void (*visit) (link)){
    link curr;
    for(curr = ls; curr!= NULL; curr = curr->next){
        (*visit) (curr);
    }
}
