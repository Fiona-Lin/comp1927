# Splay Trees
 * Balanced BST
 * All operations : O(logn) time on average.
 * Single operations: O(n) worst case time,
 * Any sequence of k ops, starting from empty tree, never > n items in tree, O(klogn) worst-case time.
 Easier to program than 2-3-4
 Fast access to entries accessed recently.

# Tree Rotations
* Splay tree are kept balanced with rotations.
```
     Y    rotate left    X
    / \   <----------   / \
   X   C               A   Y
  / \     ---------->     / \
 A   B    rotate right   B   C
```
* Splay trees are not kept perfectly balanced.

# Splay Tree Operations

## Object find(Object k);

  Begin like in ordinary BST walk down tree to entry with key k, or dead end
  Let X be node where search ended, whether it contains k or not, `Splay` X up the tree through a sequence of rotations, so X becomes root.
 ## 3 cases
* Case 1
X is left child of a right child or right child of left child
"Zig-zag"
```
     G   rotate   G   rotate     X
    / \  P left  / \  G right   / \
   P   D -----> X   D ----->   P   G
  / \          / \            /\   /\
 A   X        P   C          A  B C  D
    / \      / \
   B   C    A   B
```
* Case 2
X is left child of a left chile or right child of a right child
"Zig-zig"
```
      G   rotate     P      rotate     X
     / \  G right   / \    P right    / \
    P   D ----->   X   G    ----->   A   P
   / \            /\   /\               / \
  X   C          A  B C  D             B   G
 / \                                      / \
A   B                                    C   D
```
Repeat case1 and case2

* Case 3
X is child of the root.
"Zig"
```
     P    rotate left    X
    / \   <----------   / \
   X   C               A   P
  / \     ---------->     / \
 A   B    rotate right   B   C
```

* A node initially at depth d on access from root to X more to find depth < 3+d/2.

# Object first();
# Object last();

Find entry with min/max key, Splay it to root.

# void first(Object k Object v);
  Insert new entry(k, v).
  Splay new node to the root.

# Object remove(Object k);

An entry having key k is removed from tree, as with ordinary BST.
Let x to be the node removed from the tree. Splay X's parent to root.

e.g. remove(2);
```
     2             4             5
    / \           / \           / \
   1   7         1   7         4   7
      / \  ==>      / \  ==>  /     \
     5   8         5   8     1       8
    /
   4
```
* If key k is not in tree, splay the node where the search ended to the root.
