#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

static link makeLink(int data) {
    link node = (link)malloc(sizeof(struct _node));
    if (node != NULL) {
        node -> item = data;
        node -> next = NULL;
    }
    return node;
}

static dlink makeDlink(int data) {
    dlink dnode = malloc(sizeof(struct _dnode));
    if (dnode != NULL) {
        dnode -> item = data;
        dnode -> next = NULL;
        dnode -> prev = NULL;
    }
    return dnode;
}



void printList (link list) {
    link curr = list;
    while (curr != NULL) {
        printf ("[%d]->", curr->item);
        curr = curr->next;
    }
    printf ("[X]\n");
}


int sumListItems (link ls) {
    int total = 0;
    if(ls != NULL) {
        link cur = ls;
        int i = 1;
        while (cur -> next != ls || i > 0) {
            total += cur->item;
            cur = cur -> next;
            i--;
        }
        if (ls -> next != ls) {
            total += cur->item;

        }
    }
    return total;
}

void freeList(link list){
    //todo
    if (list != NULL) {
        link cur = list;
        while(cur -> next != list) {
            cur = cur -> next;
        }
        cur -> next = NULL;
        cur = list;
        while (list != NULL) {
            cur = list;
            list = list -> next;
            free(cur);
        }
    }
}

dlink doublify (link list) {
    dlink head = NULL;
    dlink dcur = NULL;
    if (list != NULL) {
        link cur = list;
        int i = 1;
        while(cur -> next != list || i == 0) {
            cur = cur -> next;
            i--;
        }
        cur -> next = NULL;
        cur = list;
        head = makeDlink(cur -> item);
        dcur = head;
        while (cur -> next != NULL) {
            cur = cur -> next;
            dcur -> next = makeDlink(cur -> item);
            dcur -> next -> prev = dcur;
            dcur = dcur -> next;
        }
        cur -> next = list;
    }
    return head;
}

void freeDList(dlink list){
    //todo
    dlink temp = NULL;
    while (list != NULL) {
        temp = list;
        list = list -> next;
        free(temp);
    }
}

// create a circular list with the number of nodes specified with
// each link storing data from 1 to the number of nodes specified
link create_circular_list(int num_nodes) {
    // todo
    link head = NULL;
    link cur = NULL;
    int i = 1;
    if(num_nodes >= 1) {
        while (i <= num_nodes) {
            if (i == 1) {
                head = makeLink(i);
                cur = head;
            } else {
                cur -> next = makeLink(i);
                cur = cur -> next;
            }
            i++;
        }
        cur->next = head;
    }
    return head;
}

// print the data in a circular fashion starting from any node
void print_nodes(link list){
    // todo
    if (list != NULL) {
        link head = list;
        link cur = head;
        int i = 1;
        while (cur -> next != head || i > 0) {
            printf ("[%d]", cur->item);
            cur = cur -> next;
            i--;
            printf ("->");
        }
        printf ("[%d]", cur->item);
        printf ("\n");
    }
}
