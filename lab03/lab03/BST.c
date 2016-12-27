//An implementation of a binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"


struct treeNode {
    TreeItem item;
    treelink left;
    treelink right;
};



static treelink createNode(TreeItem item){
     treelink t = (treelink) malloc (sizeof (*t));
     t->item = item;
     t->left = NULL;
     t->right = NULL;
     return t;
}

TreeItem getItem(treelink t){
     assert(t != NULL);
     return t->item;
}

void printTreeNode (treelink t) {
     if(t != NULL);
     printf("%d ",t->item);
}

void preorderTraversal (treelink tree, void (*visit) (treelink)) {
    if (tree == NULL) {
       return;
    }
    (*visit)(tree);
    preorderTraversal (tree->left,visit);
    preorderTraversal (tree->right,visit);
}

//This function inserts duplcates on the left
treelink insertTreeNode (treelink tree, TreeItem item) {
  if (tree == NULL) {
      tree = createNode(item);
      tree->item = item;
      tree->left = NULL;
      tree->right = NULL;
   
  } else if (tree->item < item) {
      tree->right = insertTreeNode (tree->right, item);
  } else {
      tree->left = insertTreeNode (tree->left, item);
  }
  return tree;
}

int size(treelink t){
    if(t == NULL){
        return 0;
    } else {
        return 1 + size(t->left) + size(t->right);
    }
}

//returns the node of the element with item i
treelink search(treelink t, TreeItem i){
    treelink result = NULL;
    if (t == NULL) {
        result = NULL;
    } else if( i < t->item ){
        result = search(t->left,i); 
    } else if( i > t->item ){
        result = search(t->right,i);   
    } else {
        result = t;
    }    
    return result;
}

int countLeaves(treelink tree) {
   int count = 0;
   //In-Order-Traversal
   assert (tree != NULL);
   
   if (tree->left == NULL && tree->right == NULL){
      count ++;
   }
   if (tree->left != NULL) {
      count += countLeaves(tree->left);
   }
   if (tree->right != NULL) {
      count += countLeaves(tree->right);
   }
   
   return count;
}

treelink searchInsert(treelink t, TreeItem i) {
  /* int isIn = 0;
   int item = 0;
   int nCount = 0;
   if (t->item == i) {
     isIn++;
     nCount++; 
   }
   if (tree->left != NULL && isIn == 0) {
      item = t->left->item;
      nCount++;
      isIn += searchInsert(t->left,item);
   }
   if (tree->right != NULL && isIn == 0) {
      item = t->right->item;
      nCount++;
      isIn += searchInsert(t->right,item);
   }
   if (isIn == 0 && nCount != size(t)) {
      return isIn;
   }
   else if (isIn == 0 && nCount == size(t)) {
      insertTreeNode(t, i);
      return t;
   }*/
   
    treelink result = NULL;
    if (t == NULL) {
        if (size(t) == 0){
            t = createNode(i);
            result = t;
        }
        else {
           result = insertTreeNode(t, i);
         
        }
    } else if( i < t->item ){
        result = searchInsert(t->left,i); 
    } else if( i > t->item ){
        result = searchInsert(t->right,i);   
    } 
    return result;
}

int countIf (treelink tree, int (*pred)(TreeItem)){
   int count = 0;
   assert(tree != NULL);
   count += (*pred)(tree->item);
   if (tree->left != NULL) {
      count += countIf (tree->left, pred);
   }
   if (tree->right != NULL) {
      count += countIf (tree->right, pred);
   }
   return count;
}

int isEven (TreeItem n){
   return (n%2 == 0);
}
int isOdd (TreeItem n){
   return (n%2==1);
}
int isNegative (TreeItem n){
   return (n<0);
}
