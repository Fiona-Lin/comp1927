typedef int TreeItem;
typedef struct treeNode * treelink;

#ifndef ITEM_H
#define ITEM_H

typedef void * Item;

#define ItemCopy(i)     (i)
#define ItemEQ(i1,i2)   ((i1) == (i2))
#define ItemLT(i1,i2)   ((i1) < (i2))
#define ItemGT(i1,i2)   ((i1) > (i2))
#define ItemShow(i)     printf("%p",(i))

#endif
//Functions that are provided
treelink insertTreeNode (treelink tree, TreeItem item);
void preorderTraversal (treelink tree, void (*visit) (treelink));
void printTreeNode (treelink t);
int size(treelink t);
treelink search(treelink t, TreeItem i);
TreeItem getItem(treelink t);

//Functions you need to write
int countLeaves(treelink tree);
treelink searchInsert(treelink t, TreeItem i);
int countIf (treelink tree, int (*pred)(TreeItem));
int isEven (TreeItem n);
int isOdd (TreeItem n);
int isNegative (TreeItem n);

