//An implementation of a BST with a field (size) to
//keep how many nodes are in each sub-tree
//This implementation also includes functions to balance the tree


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "Item.h"
#include "Tree.h"

//This is how many levels of the tree the TREEdisplay will print out
#define MAXLEVEL 15
#define FOUND  1
#define NOTFOUND 0
#define UNKNOWN (-1)
typedef struct node * link;

struct treeImp {
    link root;
    int balanceStrategy;
};

struct node {
    Item item;
    link left;
    link right;
    int size; //Keeps track of the number of nodes in each sub-tree
};

static link emptyTree = NULL;

static int nnodes(link t) {
    if (t == NULL) return 0;
    else {
        if (t -> size == 0) {
            return 0;
        } else
            return(nnodes(t -> left) + 1 + nnodes(t -> right));
    }
}

static void testSearchWords(Tree wordTree);
static void whiteboxTests();
//Local function prototypes
static link NEW (Item item, link l, link r, int size);
static int max(int a, int b);
static void destroyNodes(link n);


//search functions
static int searchR(link  t, Key k);
link searchSplay (link n, Key k, int * found);

//insert functions

static link insert(link currentLink, Item item);
static link insertAtRoot(link currentLink, Item item);
link insertRandom(link currentLink, Item item);
link insertSplay (link tree, Item item);

//balancing functions
static link rotLeft (link currentTree);
static link rotRight (link currentTree);
link balance(link tree);
static link partitionR (link currentTree, int pos);

//display and info functions
static int recursiveHeight(link n);
static void dump(link n, int level, int maxLevel);

static link NEW (Item item, link l, link r, int size) {
    link newLink = malloc (sizeof *newLink);
    newLink -> item = item;
    newLink -> left = l;
    newLink -> right = r;
    newLink -> size = size;
    return newLink;
}

//Initialises a tree
//In this implementation, a tree is not just a pointer to the root node
//but is a struct which contains a pointer to the root node.
Tree TREEinit(int balanceStrategy) {
    Tree t = malloc(sizeof(struct treeImp));
    assert(t!= NULL);
    if (emptyTree == NULL) {
        emptyTree = NEW(NULLitem,NULL,NULL,0);
    }
    t -> root = emptyTree;
    t -> balanceStrategy = balanceStrategy;
    if (t -> balanceStrategy == RANDOMISED) {
        srand(time(NULL)); //seed random number generator for insertRandom
    }
    return t;
}

//returns the size of the tree
int TREEcount(Tree tree) {
    if (tree -> root == NULL) return 0;
    return tree -> root -> size;
}


//YOU NEED TO MODIFY THIS FOR TASK 1
//A function that inserts an item into a binary tree and
//balances the tree, depending on the defined rebalance strategy
//We will assume we do not care about duplicates for this
void TREEinsert(Tree tree, Item it) {
    assert(tree!= NULL);
    if (tree -> balanceStrategy == NO_REBALANCE) {
        tree -> root = insert(tree -> root,it);
    } else if (tree -> balanceStrategy == REBALANCE_1) {
        tree -> root = insert(tree -> root,it);
        tree -> root = balance(tree -> root);
    } else if (tree -> balanceStrategy == REBALANCE_100) {
        tree -> root = insert(tree -> root,it);
        if (TREEcount(tree) % 100 == 0)
            tree -> root = balance(tree -> root);
    } else if (tree -> balanceStrategy == REBALANCE_1000) {
        tree -> root = insert(tree -> root,it);
        if (TREEcount(tree) % 1000 == 0)
            tree -> root = balance(tree -> root);
    } else if (tree -> balanceStrategy == RANDOMISED) {
        tree -> root = insertRandom(tree -> root, it);
    } else if (tree -> balanceStrategy == SPLAY) {
        tree -> root = insertSplay (tree -> root, it);
    } else {
        printf("BALANCE STRATEGY NOT IMPLEMENTED\n");
        printf("Preform whitebox testing\n");
        whiteboxTests(tree);
        exit(1);
    }
}

//You must change this for task 3
//Uses normal search or splay search, depending on
// the balance strategy
int TREEsearch(Tree t, Key k) {
    int result;
    assert(t != NULL);
    if (t -> balanceStrategy == SPLAY) {
        t -> root = searchSplay(t -> root, k, &result);
    } else {
        result =  searchR(t -> root,k);
    }
    return result;
}

//Finds the height of the tree
int TREEheight(Tree t) {
    assert(t != NULL);
    return recursiveHeight(t -> root);
}

void TREEdestroy(Tree t) {
    assert(t != NULL);
    testSearchWords(t);
    destroyNodes(t -> root);
    free(emptyTree);
    free(t);
}

void TREEdisplay(Tree t) {
    assert(t != NULL);
    dump(t -> root,0,MAXLEVEL);
}

//Prints out some statistics about the tree
void TREEshowStats(Tree t) {
    if (t -> balanceStrategy == NO_REBALANCE) {
        printf("No Rebalance Strategy\n");
    }else if (t -> balanceStrategy == REBALANCE_1) {
        printf("Global Rebalance Strategy 1\n");
    }else if (t -> balanceStrategy == REBALANCE_100) {
        printf("Global Rebalance Strategy 100\n");
    }else if (t -> balanceStrategy == REBALANCE_1000) {
        printf("Global Rebalance Strategy 1000\n");
    }else if (t -> balanceStrategy == RANDOMISED) {
        printf("Randomised Insertion\n");
    }else if (t -> balanceStrategy == SPLAY) {
        printf("Splay  \n");
    }else{
        printf("Unknown rebalance strategy\n");
        exit(0);
    }
    printf("#nodes = %d, height = %d\n",TREEcount(t), TREEheight(t));
}


// A local helper function to find the max of two integers
static int max(int a, int b) {
    int result;
    if (a >=b) {
        result =  a;
    }else{
        result =  b;
    }
    return result;
}

// Finds the height of a tree with root n
static int recursiveHeight(link n) {
    int result = -1;
    if (n != emptyTree) {
        result =  1 + max(recursiveHeight(n -> left),
                recursiveHeight(n -> right));
    }
    return result;
}

// A recursive version of standard BST insertion
// Modified to update the size counters
link insert (link currentLink, Item item) {

    if (currentLink == emptyTree) {
        return (NEW (item, emptyTree, emptyTree, 1));
    }
    if (less (key (item), key (currentLink -> item))) {
        currentLink -> left = insert (currentLink -> left, item);
    } else if (less (key (currentLink -> item), key (item))) {
        currentLink -> right = insert (currentLink -> right, item);
    }
    currentLink -> size++;
    return (currentLink);
}

// A recursive function that inserts the new item
// at the root of the tree. This is used in randomInsert
link insertAtRoot(link currentLink, Item item) {
    if (currentLink == emptyTree) {
        return (NEW(item,emptyTree,emptyTree,1));
    }
    //size gets updated by the rotate functions
    if (less (key (item), key (currentLink -> item))) {
        currentLink -> left = insertAtRoot (currentLink -> left, item);
        currentLink = rotRight(currentLink);
    } else {
        currentLink -> right = insertAtRoot (currentLink -> right, item);
        currentLink = rotLeft(currentLink);
    }

    return (currentLink);

}

// Randomly inserts either at the leaf of the tree or the root
link insertRandom(link currentLink, Item item) {

    if (currentLink == emptyTree) {
        return (NEW (item, emptyTree, emptyTree, 1));
    }
    //Prob 1/N
    if (rand() < RAND_MAX/(currentLink -> size+1)) {
        return insertAtRoot(currentLink,item);
    } else if (less (key (item), key (currentLink -> item))) {
        currentLink -> left = insertRandom (currentLink -> left, item);
    } else {
        currentLink -> right = insertRandom (currentLink -> right, item);
    }
    currentLink -> size++;
    return (currentLink);
}



// Performs a standard recursive search for the key in the given tree
// returns 1 if found and 0 otherwise
int searchR(link  t, Key k) {
    int returnVal;
    if (t == NULL || t == emptyTree) {
        returnVal =  0;
    }else if (less(k,t -> item)) {
        returnVal =  searchR(t -> left, k);
    }else if (greater(k,t -> item)) {
        returnVal =  searchR(t -> right, k);
    }else{
        returnVal =  1;
    }
    return returnVal;
}

//This function does not update size.

static link rotLeft (link currentTree) {
    if (currentTree == NULL || currentTree == emptyTree) return currentTree;
    link rotLTree = currentTree -> right;
    if (rotLTree == NULL || rotLTree == emptyTree) return currentTree;
    currentTree -> right = rotLTree -> left;
    rotLTree -> left = currentTree;
    currentTree -> size = nnodes(currentTree);
    rotLTree -> size = nnodes(rotLTree);
    return rotLTree;
}

//This function does not update size.
static link rotRight (link currentTree) {
    if (currentTree == NULL || currentTree == emptyTree) return currentTree;
    link rotRTree = currentTree -> left;
    if (rotRTree == NULL || rotRTree == emptyTree) return currentTree;
    currentTree -> left = rotRTree -> right;
    rotRTree -> right = currentTree;
    currentTree -> size = nnodes(currentTree);
    rotRTree -> size = nnodes(rotRTree);
    return rotRTree;
}



// partition tree at node with position pos (counting from 0) in the
// sorted sequence of all items, node become new root node.
link partitionR (link currentTree, int pos) {
    int leftSubtreeSize = currentTree -> left -> size;
    if (leftSubtreeSize > pos) {
        currentTree -> left = partitionR (currentTree -> left, pos);
        currentTree = rotRight (currentTree);
    } else if (leftSubtreeSize < pos) {
        currentTree -> right =
            partitionR (currentTree -> right, pos - 1 - leftSubtreeSize);
        currentTree = rotLeft (currentTree);
    }
    return currentTree;
}

link balance(link tree) {
    if (tree -> size >=2) {
        tree = partitionR(tree,tree -> size/2);
        tree -> left = balance(tree -> left);
        tree -> right = balance(tree -> right);
    }
    return tree;
}

link insertSplay (link tree, Item item) {
    Key v = key (item);
    if (tree == emptyTree)
        return (NEW (item, emptyTree, emptyTree, 1));

    if (less (v, key(tree -> item))) {
        if (tree -> left == emptyTree) {
            return (NEW (item, emptyTree, tree, tree -> size+1));
        }
        if (less (v, key (tree -> left -> item))) {
            tree -> left -> left = insertSplay (tree -> left -> left, item);
            tree = rotRight (tree);
        } else {
            tree -> left -> right = insertSplay (tree -> left -> right, item);
            tree -> left = rotLeft (tree -> left);
        }
        return rotRight (tree);
    } else {
        if (tree -> right == emptyTree) {
            return (NEW (item, tree, emptyTree, tree -> size+1));
        }
        if (less (key (tree -> right -> item), v)) {
            tree -> right -> right = insertSplay (tree -> right -> right, item);
            tree = rotLeft (tree);
        } else {
            tree -> right -> left = insertSplay (tree -> right -> left, item);
            tree -> right = rotRight (tree -> right);
        }
        return rotLeft (tree);
    }
}

//The function should perform rotations on all
//items in the search path in a similar way to that of
//splay tree insertion - except no node is actually inserted

//The node that contains the key
//should be rotated up and returned as the root of the tree
//and *found should be set to 1

//If the key was not found, the last node on the search
//path should be rotated up to the root of the tree
//and found should be set to 0

//returns the new root of the tree
//sets the value of *found to 0 or 1
static int match(link n, Key k) {
    assert(n != NULL);
    if (n == emptyTree) {
        //If not found, return the last node on left search path
        return NOTFOUND;
    } else if (eq(key(n -> item),k)) {
        // my base case when it found, return the found node
        return FOUND;
    }
    return UNKNOWN;
}
link searchSplay (link n, Key k, int * found) {
    *found = match(n, k);
    //start with base case, if it's found return found node
    //if it's not found or notFound, return last node on the search path
    if (*found == FOUND || *found == NOTFOUND) {
        return n;
    } else {
        if (less (k, key(n -> item))) {
            *found = match(n -> left, k);
            if (*found == FOUND || *found == NOTFOUND) {
                return n;
            } else {
                //no matter found or not, return node will rotate upward, n got splay recursively
                if (less (k, key (n -> left -> item))) {
                    n -> left -> left = searchSplay(n -> left -> left, k, found);
                    n = rotRight (n);
                } else if (greater(k, key (n -> left -> item))) {
                    n -> left -> right = searchSplay (n -> left -> right, k, found);
                    n -> left = rotLeft (n -> left);
                }
                return rotRight (n);
            }
        } else {
            *found = match(n -> right, k);
            if (*found == FOUND || *found == NOTFOUND) {
                return n;
            } else {
                //no matter found or not, return node will rotate upward, n got splay recursively
                if (less (key (n -> right -> item), k)) {
                    n -> right -> right = searchSplay (n -> right -> right, k, found);
                    n = rotLeft (n);
                } else if (greater(key (n -> right -> item), k)) {
                    n -> right -> left = searchSplay (n -> right -> left, k, found);
                    n -> right = rotRight (n -> right);
                }
                return rotLeft (n);
            }
        }
    }
}

static void destroyNodes(link n) {
    if ( n != emptyTree) {
        destroyNodes(n -> left);
        destroyNodes(n -> right);
        free(n -> item);
        free(n);
    }
}

// Prints out a tree
// Handles recursion and level maintenance
static void dump(link n, int level, int maxLevel) {
    if (n == NULL || n == emptyTree) {
        printf("X\n");
    } else if (level == maxLevel) {
        printf("...\n");
    }else {
        int i;
        showItem(n -> item);
        printf(" (%d) ",n -> size);
        printf("\n");
        if (n -> left != NULL) {
            for (i = 0; i < level; i++) {
                printf("|  ");
            }
            printf("|--L: ");
            dump(n -> left, level+1, maxLevel);
        }
        if (n -> right != NULL) {
            for (i = 0; i < level; i++) {
                printf("|  ");
            }
            printf("|--R: ");
            dump(n -> right, level+1, maxLevel);
        }
    }
}

void testRotateRight(Tree t) {
    int i = 0;
    int n1Size = 0;
    int n2Size = 0;
    int t1Size = 0;
    int t2Size = 0;
    int t3Size = 0;
    link n1 = t -> root;
    link n2 = NULL;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test link rotRight (link currentTree) <<<<<\n");
    printf("------------------------------------------------------");

    printf("\n## Test %d: empty tree\n",++i);
    //assuming n1 rotate left become n2,
    //because n1 is empty(NULL),
    //after it rotate still empty(NULL)
    n1Size = nnodes(n1);
    n2 = rotRight(n1);
    n2Size = nnodes(n2);
    //check the empty tree n2 addree is still same n1
    assert(n2 == n1);
    //check the size of n2 is same as size of n1
    assert(n1Size == n2Size);
    printf("\n ## passed ##\n");

    printf("\n## Test %d: 1 node tree\n",++i);
    n1 = insert(n1,"hello");
    n1Size = nnodes(n1);
    //assuming n1 rotate right become n2,
    //because n1 left subtree is empty(NULL),
    //after it rotate still n1
    n2 = rotRight(n1);
    n2Size = nnodes(n2);
    //check the size of n2 is same as size of n1
    assert(n1Size == n2Size);
    //check the tree n2 addree is same as the tree n1
    assert(n2 == n1);
    printf("\n ## passed ##\n");

    printf("\n## Test %d: 2 nodes tree\n",++i);
    n2 = insert(n2,"every");
    n2Size = nnodes(n2);
    n1 = rotRight(n2);
    n1Size = nnodes(n1);
    //check the size of n2 is same as size of n1
    assert(n1Size == n2Size);
    //check n1 get n2's subTree
    assert(n1 -> left == emptyTree);
    assert(n1 -> right -> left == emptyTree);
    assert(n1 -> right -> right == emptyTree);
    //check the tree n2 addree is same as the tree n1
    assert(n1 != n2);
    printf("\n ## passed ##\n");

    /*     n1           n2
     *   /   \          / \
     *  n2   t3 ==>   t1  n1
     * / \               / \
     * t1 t2            t2  t3
     */

    printf("\n## Test %d: 7 nodes tree\n",++i);
    n1 = insert(n1, "body");
    n1 = insert(n1, "one");
    n1 = insert(n1, "world");
    n1 = insert(n1, "left");
    n1 = insert(n1, "xyz");
    n1Size = nnodes(n1);
    t1Size = nnodes(n1 -> left -> left);
    t2Size = nnodes(n1 -> left -> right);
    t3Size = nnodes(n1 -> right);
    n2 = rotRight(n1);
    n2Size = nnodes(n2);
    //check the size of n2 is same as size of n1
    assert(n1Size == n2Size);
    //check n1 get n2's subTree and the size is updated
    assert(nnodes(n1) == (1 + t2Size + t3Size));
    assert(t1Size == nnodes(n2 -> left));
    assert(t2Size == nnodes(n2 -> right -> left));
    assert(t3Size == nnodes(n2 -> right -> right));
    printf("\n ## passed ##\n");
    //TREEdestroy(t);
}

void testRotateLeft(Tree t) {
    int i = 0;
    int n1Size = 0;
    int n2Size = 0;
    int t1Size = 0;
    int t2Size = 0;
    int t3Size = 0;
    link n2 = t -> root;
    link n1 = NULL;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test link rotLeft (link currentTree) <<<<<\n");
    printf("------------------------------------------------------");

    printf("\n## Test %d: empty tree\n",++i);
    //assuming n2 rotate left become n1,
    //because n1/n2 are empty(NULL),
    //after it rotate, both are still empty(NULL)
    n2Size = nnodes(n2);
    n1 = rotLeft(n2);
    n1Size = nnodes(n1);
    //check the empty tree n2 addree is still same n1
    assert(n2 == n1);
    //check the size of n1 is same as old size of n2
    assert(n1Size == n2Size);
    //check the size of n2 after left rotation is same n2Size
    assert(nnodes(n2) == n2Size);
    printf("\n ## passed ##\n");

    printf("\n## Test %d: 1 node tree\n",++i);
    n2 = insert(n2,"hello");
    n2Size = nnodes(n2);
    //assuming n2 rotate left become n1,
    //because n2 right subtree is empty(NULL),
    //after it rotate, n1 is still n2
    n1 = rotLeft(n2);
    n1Size = nnodes(n1);
    //check the size of n2 is same as size of n1
    assert(n1Size == n2Size);
    //check the tree n2 addree is same as the tree n1
    assert(n2 == n1);
    //check the size of n2 after left rotation is same n2Size
    assert(nnodes(n2) == n1Size);
    printf("\n ## passed ##\n");

    printf("\n## Test %d: 2 nodes tree\n",++i);
    n2 = insert(n2, "world");
    //assuming n2 rotate left become n1,
    //because n2 right subtree is empty(NULL),
    //after it rotate, n1 is still n2
    n2Size = nnodes(n2);
    n1 = rotLeft(n2);
    n1Size = nnodes(n1);
    assert(n1Size == n2Size);
    assert(n1 -> right == emptyTree);
    assert(n1 -> left -> right == emptyTree);
    assert(n1 -> left -> left == emptyTree);
    printf("\n ## passed ##\n");

    /*     n1           n2
     *   /   \          / \
     *  n2   t3 <==   t1  n1
     * / \               / \
     * t1 t2            t2  t3
     */

    printf("\n## Test %d: 7 nodes tree\n",++i);
    n2 = insert(n2,"every");
    n2 = insert(n2, "body");
    n2 = insert(n2, "one");
    n2 = insert(n2, "left");
    n2 = insert(n2, "xyz");
    n2Size = nnodes(n2);
    t1Size = nnodes(n2 -> left);
    t2Size = nnodes(n2 -> right -> left);
    t3Size = nnodes(n2 -> right -> right);
    n1 = rotLeft(n2);
    n1Size = nnodes(n1);
    assert(n1Size == n2Size);
    assert(nnodes(n2) == (1 + t2Size + t1Size));
    assert(t1Size == nnodes(n1 -> left -> left));
    assert(t2Size == nnodes(n1 -> left -> right));
    assert(t3Size == nnodes(n1 -> right));
    printf("\n ## passed ##\n");
}

void testSearchWords(Tree wordTree){
    int size = TREEcount(wordTree);
    int i;
    char * testData[16] = { "apple","egg","lettuce","quince","turnip", "fiona","arrange","kittenish","cerulean","outermost","excising","grimmer","reform","snoop","trike","éclair"};

    if(size == 13) {
        for (i = 0; i < 6; i++) {
            clock_t begin = clock();
            int res = TREEsearch(wordTree,testData[i]);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nSearch word [%s] takes %lf seconds, Found: %d\n", testData[i], time_spent, res);
            TREEshowStats(wordTree);
        }
    } else {
        for (i = 5; i < 16; i++) {
            clock_t begin = clock();
            int res = TREEsearch(wordTree,testData[i]);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nSearch word [%s] takes %lf seconds, Found: %d\n ", testData[i], time_spent, res);
            TREEshowStats(wordTree);
        }
    }

}

void whiteboxTests(Tree t) {
    testRotateRight(t);
    testRotateLeft(t);
}
