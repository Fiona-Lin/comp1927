#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

void testCountLeaves();
void testCountIf();

int main(int argc, char * argv []) {

    testCountLeaves();
    testCountIf();
    testSearchInsert();

    return EXIT_SUCCESS;
}
// Should also test that insert node works for when there's no elements in the tree

void testCountLeaves() {
    int i= 0;
    int c;

    treelink t = NULL;
    printf("\n## Test %d: 0 leaf tree\n", ++i);
    c = countLeaves(t);
    assert(c == 0);
    printf("%d leaves tree\t ## passed\n", c);

    printf("\n## Test %d: 1 leaf tree\n", ++i);
    t = insertTreeNode(NULL, 10);
    c = countLeaves(t);
    assert(c == 1);
    printf("%d leaves tree\t ## passed\n", c);

    printf("\n## Test %d: 2 leaf tree\n", ++i);
    insertTreeNode(t, 4);
    insertTreeNode(t, 12);
    c = countLeaves(t);
    assert(c == 2);
    printf("%d leaves tree\t ## passed\n", c);

    printf("\n## Test %d: 3 leaf tree\n", ++i);
    insertTreeNode(t, 2);
    insertTreeNode(t, 7);
    c = countLeaves(t);
    assert(c == 3);
    printf("%d leaves tree\t ## passed\n", c);

    printf("\n## Test %d: 4 leaf tree\n", ++i);
    insertTreeNode(t, 11);
    insertTreeNode(t, 18);
    c = countLeaves(t);
    assert(c == 4);
    printf("%d leaves tree\t ## passed\n", c);


    printf("\n## Test %d: 7 leaf tree\n", ++i);
    insertTreeNode(t, 1);
    insertTreeNode(t, 3);
    insertTreeNode(t, 6);
    insertTreeNode(t, 8);
    insertTreeNode(t, 14);
    insertTreeNode(t, 26);

    c = countLeaves(t);
    assert(c == 7);
    printf("%d leaves tree\t ## passed\n", c);
}
void testCountIf() {
     int i= 0;
    int c;

    treelink t = NULL;
    printf("\n## Test %d: 0 even and 0 odd node tree\n", ++i);
    c = countIf(t,isEven);
    assert(c == 0);
    c = countIf(t,isOdd);
    assert(c == 0);

    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 1 even node tree\n", ++i);
    t = searchInsert(NULL, 10);
    c = countIf(t,isEven);
    assert(c == 1);
    c = countIf(t,isOdd);
    assert(c == 0);
    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 3 even nodes tree\n", ++i);
    searchInsert(t, 4);
    searchInsert(t, 12);
    c = countIf(t,isEven);
    assert(c == 3);
    c = countIf(t,isOdd);
    assert(c == 0);
    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 4 even nodes tree\n", ++i);
    searchInsert(t, 2);
    searchInsert(t, 7);
    c = countIf(t, isEven);
    assert(c == 4);
    c = countIf(t, isOdd);
    assert(c == 1);
    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 5 even nodes tree\n", ++i);
    searchInsert(t, 11);
    searchInsert(t, 18);
    c = countIf(t, isEven);
    assert(c == 5);
    c = countIf(t, isOdd);
    assert(c == 2)
    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 9 even nodes tree\n", ++i);
    searchInsert(t, 1);
    searchInsert(t, 3);
    searchInsert(t, 6);
    searchInsert(t, 8);
    searchInsert(t, 14);
    searchInsert(t, 26);
    
    c = countIf(t, isEven);
    assert(c == 9);
    c = countIf(t, isOdd);
    assert(c == 4);
    printf("%d even nodes tree\n ## passed\n", c);


    printf("\n## Test %d: 0 negative node tree\n", ++i);
    c = countIf(t,isNegative);
    assert(c == 0);
    printf("%d negative nodes tree\n ## passed\n", c);
    
    printf("\n## Test %d: 1 negative node tree\n", ++i);
    t = insertTreeNode(NULL, 10);
    c = countIf(t,isNegative);
    assert(c == 1);
    printf("%d negative nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 3 negative nodes tree\n", ++i);
    insertTreeNode(t, -4);
    insertTreeNode(t, -12);
    c = countIf(t,isNegative);
    assert(c == 3);
    printf("%d negative nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 4 negative nodes tree\n", ++i);
    insertTreeNode(t, -2);
    insertTreeNode(t, -7);
    c = countIf(t, -isNegative);
    assert(c == 4);
    printf("%d negative nodes tree\n ## passed\n", c);
    
    printf("\n## Test %d: 5 negative nodes tree\n", ++i);
    insertTreeNode(t, -11);
    insertTreeNode(t, -18);
    c = countIf(t, -isNegative);
    assert(c == 5);
    printf("%d negative nodes tree\n ## passed\n", c);
    
    
    printf("\n## Test %d: 9 negative nodes tree\n", ++i);
    insertTreeNode(t, -1);
    insertTreeNode(t, -3);
    insertTreeNode(t, -6);
    insertTreeNode(t, -8);
    insertTreeNode(t, -14);
    insertTreeNode(t, -26);
    
    c = countIf(t, -isNegative);
    assert(c == 9);
    printf("%d negative nodes tree\n ## passed\n", c);
}

void testSearchInsert(){
//    test searching for 0
    int i= 0;
    int c;
    
    printf("%d even nodes tree\n ## passed\n", c);
    
    printf("\n## Test %d: 1 even node tree\n", ++i);
    t = searchInsert(NULL, 10);
    c = size(t);
    assert(c == 1);
    printf("\n ## passed\n", c);

    printf("\n## Test %d: 3 even nodes tree\n", ++i);
    searchInsert(t, 4);
    searchInsert(t, 12);
    c = countIf(t,isEven);
    assert(c == 3);
    c = countIf(t,isOdd);
    assert(c == 0);
    printf("%d even nodes tree\n ## passed\n", c);

    printf("\n## Test %d: 4 even nodes tree\n", ++i);
    searchInsert(t, 2);
    searchInsert(t, 7);
    c = countIf(t, isEven);
    assert(c == 4);
    c = countIf(t, isOdd);
    assert(c == 1);
    printf("%d even nodes tree\n ## passed\n", c);
    
    printf("\n## Test %d: 5 even nodes tree\n", ++i);
    searchInsert(t, 11);
    searchInsert(t, 18);
    c = countIf(t, isEven);
    assert(c == 5);
    c = countIf(t, isOdd);
    assert(c == 2)
    printf("%d even nodes tree\n ## passed\n", c);
    
    
    printf("\n## Test %d: 9 even nodes tree\n", ++i);
    searchInsert(t, 1);
    searchInsert(t, 3);
    searchInsert(t, 6);
    searchInsert(t, 8);
    searchInsert(t, 14);
    searchInsert(t, 26);
    
    c = countIf(t, isEven);
    assert(c == 9);
    c = countIf(t, isOdd);
    assert(c == 4);
    printf("%d even nodes
}

