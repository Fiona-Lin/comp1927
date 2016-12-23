#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

treelink newTNode(TreeItem i);
int main(int argc, char * argv []) {
    treelink  t = newTNode(10);
    treelink  tl = newTNode(4);
    treelink  tr = newTNode(12);
    printf("\n## Test 1. 1 leaf tree\n");
    int c = countLeaves(t);
    assert(c == 1);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test 2. 2 leaf tree\n");
    t -> l = tl;
    c = countLeaves(t);
    assert(c == 2);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test 3. 3 leaf tree\n");
    t -> r = tr;
    c = countLeaves(t);
    assert(c == 3);
    printf("%d tree\t ## passed\n", c);



    return EXIT_SUCCESS;
}

treelink newTNode(TreeItem i) {
    treelink  t = malloc(sizeof(struct treeNode));
    t -> left = NULL;
    t -> right = NULL;
    t -> item = i;
    return t;
}
