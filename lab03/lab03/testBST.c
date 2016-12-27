#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

int main(int argc, char * argv []) {
    i= 0;

    printf("\n## Test %d: 0 leaf tree\n", ++i);
    
    printf("\n## Test %d: 1 leaf tree\n", ++i);
    treelink t = insertTreeNode(NULL, 10);
    c = countLeaves(t);
    assert(c == 1);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test %d: 2 leaf tree\n", ++i);
    insertTreeNode(t, 4);
    insertTreeNode(t, 12);
    c = countLeaves(t);
    assert(c == 2);
    printf("%d tree\t ## passed\n", c);

    printf("\n## Test %d: 3 leaf tree\n", ++i);
    insertTreeNode(t, 2);
    insertTreeNode(t, 7);
    c = countLeaves(t);
    assert(c == 3);
    printf("%d tree\t ## passed\n", c);
    
    printf("\n## Test %d: 4 leaf tree\n", ++i);
    insertTreeNode(t, 11);
    insertTreeNode(t, 18);
    c = countLeaves(t);
    assert(c == 4);
    printf("%d tree\t ## passed\n", c);
    
    
    printf("\n## Test %d: 7 leaf tree\n", ++i);
    insertTreeNode(t, 1);
    insertTreeNode(t, 3);
    insertTreeNode(t, 6);
    insertTreeNode(t, 8);
    insertTreeNode(t, 14);
    insertTreeNode(t, 26);
    
    c = countLeaves(t);
    assert(c == 7);
    
    
    
    printf("%d tree\t ## passed\n", c);
    


    return EXIT_SUCCESS;
}
// Should also test that insert node works for when there's no elements in the tree

