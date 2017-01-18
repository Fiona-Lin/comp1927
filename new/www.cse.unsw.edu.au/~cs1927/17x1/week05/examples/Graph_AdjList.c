#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

typedef struct vNode *VList;
struct vNode { 
    Vertex v; 
    VList next; 
}; 

struct GraphRep { 
    int nV; // #vertices 
    int nE; // #edges VList 
    VList *edges; // array of lists 
}; 

//O(V) - Hmmmm O(E) since we allow multiple edges
int isAdjacent(Graph g,Vertex v, Vertex w){
    assert(g!= NULL && validV(g,v) && validV(g,w));  
    VList curr = g->edges[v];
    while(curr != NULL){
        if(curr->v == w) return 1;
        curr= curr->next;
    }
    return 0;
}

//Inserts a vertex at the beginning of the list
//returns the new beginning ofthe list
static VList insertVList(Vertex v,VList list){
    VList newNode = malloc(sizeof(struct Vnode));
    newNode->v = v;
    newNode->next = list;
    return newNode;  
}

//e.v e.w //2,1
void insertE(Graph g, Edge e) { 
   assert(g != NULL && e.v < g->nV && e.w < g->nV);
   g->edges[e.v] = insertVList(e.w,g->edges[e.v]);
   g->edges[e.w] = insertVList(e.v,g->edges[e.w]);
   g->nE++;
}

Graph newGraph(int nV) { 
    int i; 
    Graph g = malloc(sizeof(struct GraphRep));
    g->edges = malloc(nV* sizeof(VList));
    for(i=0; i<nV; i++){
        g->edges[i] = NULL;
    }
    g->nV = nV;
    g->nE = 0;
    return g; 
} 


// local checking function
static int validV(Graph g, Vertex v) {
    return (v >= 0 && v < g->nV);
}

// Does not allow self-loops
Edge mkEdge(Graph g, Vertex v, Vertex w) { 
    assert(v != w); 
    assert(validV(g,v) && validV(g,w));
    Edge e = {v,w};
    return e;
}

/
void showGraph(Graph g) { 
    assert(g != NULL); 
    printf("V=%d, E=%d\n", g->nV, g->nE); 
    int i; 
    for (i = 0; i < g->nV; i++) { 
        VList n = g->edges[i]; 
        while (n != NULL) { 
            printf("%d-%d ",i,n->v); 
            n = n->next; 
        } 
        if (g->edges[i] != NULL) 
            printf("\n"); 
        } 
} 

int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g){
    assert(g != NULL);
    return g->nE;
}

void destroyGraph(Graph g){
  printf("NOT DONE\n");
} 
