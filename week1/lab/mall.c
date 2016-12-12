#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

// insert proper tests here
int main (int argc, const char * argv[]) {
    char * p = malloc(sizeof(char)*9);
    int ch = 'a';
    int i;
    for (i = 0; i < 9; i++) {
        p[i] = ch;
        ch++;
    }

    printf("*p = %s\n", p);
    free(p);
    return 0;
}
