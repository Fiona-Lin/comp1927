//Adjacency list graph representation

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "GRAPH.h"


typedef struct vNode *VList;
struct vNode {
    Vertex v;
    VList next;
};

struct graphRep {
    int nV; // #vertices
    int nE; // #edges VList
    VList *adj; // array of lists
};

