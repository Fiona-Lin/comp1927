#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"
#include "Stack.h"
#include "Queue.h" //so we can do a level order traversal

struct treeNode {
    TreeItem item; //int
    Treelink left; //struct treeNode *
    Treelink right;
};

//Local helper functions
static Treelink createNode(TreeItem item){
    Treelink ret = calloc(sizeof(struct treeNode), 1);
    ret -> item = item;
    return ret;
}

void destroyTree(Treelink tree) {
    if (tree != NULL) {
        destroyTree(tree -> left);
        destroyTree(tree -> right);
    }
    free(tree);
}

static int max(TreeItem i1, TreeItem i2) {
    int max = i1;
    if(max < i2) max = i2;
    return max;
}

int height(Treelink t) {
    int h = 0;
    if (t != NULL) {
        h++;
        int lH = height(t -> left);
        int rH = height(t -> right);
        if (lH < rH) h = rH;
        else h = lH;
    }
    return h;
}

//what size?
int size(Treelink t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + size(t->left) + size(t -> right);
    }
}

//Interface functions
TreeItem getItem(Treelink node){
    return node -> item;
}

Treelink createTree(void){
    return NULL;
}

//returns the node of the element with item i
Treelink search(Treelink t, TreeItem i){
    Treelink ret = NULL;
    if (t -> item == i) {
        ret = t;
    } else {
        ret = search(t -> left, i);
        if (ret == NULL) {
            ret = search(t -> right, i);
        }
    }
    return ret;
}

//returns the node of the element with item i
Treelink searchIterative(Treelink t, TreeItem i){
    Treelink ret = NULL;
    Treelink cur = t;
    while (cur != NULL) {
        if (i < cur -> item) {
            cur = cur -> left;
        } else if (i > cur -> item) {
            cur = cur -> right;
        } else {
            ret = cur;
            cur = NULL;
        }
    }
    return ret;
}

void inorderTraversal (Treelink tree) {
    if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        printf("%d ", tree -> item);
    else if (tree != NULL) {
        if (tree -> left != NULL)
            inorderTraversal(tree -> left);
        printf("%d ", tree -> item);
        if (tree -> right != NULL)
            inorderTraversal(tree -> right);
    }
}

void postorderTraversal(Treelink tree) {
    if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        printf("%d ", tree -> item);
    else if (tree != NULL) {
        if (tree -> left != NULL)
            inorderTraversal(tree -> left);
        if (tree -> right != NULL)
            inorderTraversal(tree -> right);
        printf("%d ", tree -> item);
    }
}

void preorderTraversal(Treelink tree) {
    if (tree != NULL && tree -> left == NULL && tree -> right == NULL)
        printf("%d ", tree -> item);
    else if (tree != NULL) {
        printf("%d ", tree -> item);
        if (tree -> left != NULL)
            inorderTraversal(tree -> left);
        if (tree -> right != NULL)
            inorderTraversal(tree -> right);
    }
}


//Returns the root of the tree
//inserts duplicates on theleft hand side of tree
Treelink insertRec(Treelink tree, TreeItem item) {
    Treelink ret = createNode(item);
    if(tree == NULL) {
        tree = ret;
    } else if (item > tree -> item) {
        tree -> right = insertRec(tree -> right, item);
    } else {
        tree -> left = insertRec(tree -> left, item);
    }
    return tree;
}

//Returns the root of the tree
//inserts duplicates on theleft hand side of tree
Treelink insertIterative(Treelink tree, TreeItem key) {
    Treelink ret = createNode(item);
    Treelink cur = tree;
    while (cur != NULL) {
        if (item > cur -> item) {
            cur = cur -> right;
        } else {
            cur = cur -> left;
        }
    }
    cur = ret;
    return tree;
}

void levelOrderTraversal(Treelink tree) {
    if (tree != NULL)
        printf("%d ", tree -> item);
    if (tree -> left != NULL)
        levelOrderTraversal(tree -> left);
    if (tree -> right != NULL)
        levelOrderTraversal(tree -> right);
}

//Same as recursive Preorder
void mysteryIterativeTraversal(Treelink tree) {

}

//Assume t1 is the left subtree and t2 the right subtree
static Treelink join(Treelink t1, Treelink t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    else {
        Treelink lm = t2;
        Treelink pre = NULL;
        while (lm -> left != NULL) {
            pre = lm;
            lm = lm -> left;
        }
        if (pre != NULL) {
            pre -> left = lm -> right;
            lm -> right = t2;
        }
        lm -> left = t1;
    }
}

Treelink delete(Treelink tree, TreeItem item) {
    if (tree == NULL) {
        return tree;
    } else if (item < tree -> item) {
        tree -> left = delete(tree -> left, item);
    } else if (item > tree -> item) {
        tree -> right = delete(tree -> right, item);
    } else {
        Treelink del = tree;
        tree = join(tree -> left, tree -> right);
        free(del);
        return tree;
    }
}

static void doShowBSTree(Treelink t, int level) {

}

void showBSTree(Treelink t) {

}

//PRACTICE QUESTIONS
//Some of these questions would only
//be doable assuming the tree has int items.
int sumEven(Treelink tree){
    int res = 0;
    if (tree != NULL) {

    }
}

TreeItem getSmallest(Treelink tree) {

}

//An internal node has at least one non-null child
int numInternalNodes(Treelink tree){

}

//Does a path from the root to an external node(in this case an external node can be considered to have at least one null child)
//have the given sum?
//0 false
//1 true
int hasPathSum(Treelink tree, int sum) {

}

/*
//Double tree
//
//     2
//   /   \
//  1     3
//
// would become
//        2
//      /  \
//     2    3
//    /    /
//   1    3
//  /
// 1
*/

void doubleTree(Treelink tree) {

}

//Delete nodes with items < min  or > max
Treelink trimTree(Treelink tree, int min, int max);


