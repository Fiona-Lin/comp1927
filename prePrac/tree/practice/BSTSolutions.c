#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"



struct treeNode {
    TreeItem item; //int
    Treelink left; //struct treeNode *
    Treelink right;
};

static Treelink createNode(TreeItem item);

//PRACTICE QUESTIONS
//Some of these questions would only 
//be doable assuming the tree has int items.
/*
   7
   / \
   3   12
   /   /  \
   1   8    13
   \
   2
   */
int sumEven(Treelink tree){

}


Treelink getSmallest(Treelink tree){

}

//An internal node has at least one non-null child
int numInternalNodes(Treelink tree){

}

//Does a path from the root to a leaf node
//(in this case a leaf node can be 
//considered to have at least one null child) 
//have the given sum?
//0 false
//1 true
/*
//      5
//    /    \
//   2     7
//    \   / \
//     3 6 10
*/
int hasPathSum(Treelink tree, int sum){


}
/*Double tree
//     2        
//   /   \
2     3
/     /  
// 1     3
/
1     
//
// would become
//        2
//      /  \
//     2    3
//    /    /
//   1    3
//  /
// 1
//
 **/    
void doubleTree(Treelink tree){


}

//Delete and free nodes with items < min  or > max
//trimTree(tree,3,8)
/*      6
//    /   \
//   2     8
//    \   / \ 
//     4 7  9 
*/

/*       6
//      / \
//     4   8
//         /
//        7
*/
Treelink trimTree(Treelink tree, int min, int max){

}

//Local helper functions
static Treelink createNode(TreeItem item){

}


void destroyTree(Treelink tree){

}


static int max(TreeItem i1, TreeItem i2){

}

int height(Treelink t){

}

int size(Treelink t){

}

//Interface functions

TreeItem getItem(Treelink node){

}

Treelink createTree(void){

}




//returns the node of the element with item i
Treelink search(Treelink t, TreeItem i){

}

//returns the node of the element with item i
Treelink searchIterative(Treelink t, TreeItem i){

}




void inorderTraversal (Treelink tree) {

}

void postorderTraversal (Treelink tree) {

}



void preorderTraversal (Treelink tree){

}


//Returns the root of the tree
//inserts duplicates on theleft hand side of tree
Treelink insertRec (Treelink tree, TreeItem item) {

}

//Returns the root of the tree
//inserts duplicates on theleft hand side of tree
Treelink insertIterative(Treelink tree, TreeItem key) {

}




//Assume t1 is the left subtree and t2 the right subtree
static Treelink join(Treelink t1, Treelink t2){

}

Treelink delete(Treelink tree, TreeItem item){

}

static void doShowBSTree(Treelink t, int level) {

}

void showBSTree(Treelink t) {

}



