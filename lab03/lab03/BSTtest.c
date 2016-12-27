#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

int main(int argc, char * argv []) {
    int i = 0;
    printf("\n## Test %d. 1 leaf tree\n", ++i);
    treelink t = insertTreeNode(NULL, 10);
    int c = countLeaves(t);
    assert(c == 1);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test %d. 2 leaf tree\n", ++i);
    insertTreeNode(t, 4);
    insertTreeNode(t, 12);
    c = countLeaves(t);
    assert(c == 2);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test %d. 3 leaf tree\n", ++i);
    insertTreeNode(t, 1);
    insertTreeNode(t, 5);
    c = countLeaves(t);
    assert(c == 3);
    printf("%d tree\t ## passed\n", c);



    return EXIT_SUCCESS;
}
// Should also test that insert node works for when there's no elements in the tree

