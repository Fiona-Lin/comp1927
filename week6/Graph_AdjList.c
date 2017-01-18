#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Stack.h"

// local checking function
static int validV(Graph g, Vertex v);

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

int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g){
    assert(g != NULL);
    return g->nE;
}

// Does not allow self-loops
Edge mkEdge(Graph g, Vertex v, Vertex w) { 
    //assert(v != w); 
    assert(validV(g,v) && validV(g,w));
    Edge e = {v,w};
    return e;
}

// local checking function
static int validV(Graph g, Vertex v) {
    return (v >= 0 && v < g->nV);
}


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

//O(V)
int adjacentVertices(Graph g, Vertex v, Vertex adj[]){
    int counter = 0;
    assert(g!=NULL && validV(g,v));
    VList tmp = g->edges[v];
    while(tmp != NULL){
        adj[counter] = tmp->v;
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

//Inserts a vertex at the beginning of the list
//returns the new beginning ofthe list
static VList insertVList(Vertex v,VList list){
    VList newNode = malloc(sizeof(struct vNode));
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
    assert(g != NULL);
    g->edges = malloc(nV* sizeof(VList));
    assert(g->edges != NULL); 
    for(i=0; i<nV; i++){
        g->edges[i] = NULL;
    }
    g->nV = nV; 
    g->nE = 0; 
    return g; 
} 


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


Graph copyGraph(Graph g) { return NULL; }

  void destroyGraph(Graph g){
  printf("NOT DONE\n");
} 

//O(V) - O(E) since we allow multiple edges
int degree(Graph g, Vertex v){
    assert(g!= NULL && validV(g,v)); 
    int d = 0;
    // TO BE COMPLETED
    return d;
}

int * pre = NULL; //order and visited
Vertex *st = NULL; //parent - path
int count=0;

// dfSearch using Stack
//The initialisation of variables etc before we call the dfs function
void dfSearchIterative(Graph g){
    printf("\nDFS ITERATIVE...NOT DONE\n");
}

// dfSearch using Queue
void bfSearch(Graph g) {
    printf("BFSearch...NOT DONE\n"); }

void findShortestPath(Graph g, Vertex src,Vertex dest) {
    printf("findShortestPath...NOT DONE\n");
}



