#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "pq.h"

#define MAX_INPUT 100
#define MAX_PQ 10

int main(int argc, char * argv[]){
    char buffer[MAX_INPUT];
    PriQ pq = initPriQ();
    int priority;
    int num = 0;
    while(fgets(buffer,MAX_INPUT,stdin) != NULL && num < MAX_PQ){
        char * illness = malloc((strlen(buffer)+1)*sizeof(char));
        if(sscanf(buffer,"%d %[^\n]",&priority,illness) != 2) break;

        insert(pq,newItem(priority,illness));

        num++;
    }    

    while(sizePriQ(pq) > 0){
        printf("Treating %s\n",value(delete(pq)));

    }
    return 0;
}
